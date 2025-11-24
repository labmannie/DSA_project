// DOM Elements
const taskForm = document.getElementById('taskForm');
const taskNameInput = document.getElementById('taskName');
const taskPriorityInput = document.getElementById('taskPriority');
const currentTaskDisplay = document.getElementById('currentTaskDisplay');
const completeBtn = document.getElementById('completeBtn');
const heapVisualizer = document.getElementById('heapVisualizer');

const API_URL = 'http://localhost:3000';

// Event Listener: Add Task
taskForm.addEventListener('submit', async (e) => {
    e.preventDefault();

    const name = taskNameInput.value;
    const priority = parseInt(taskPriorityInput.value);

    if (name && priority) {
        try {
            const res = await fetch(`${API_URL}/add-task`, {
                method: 'POST',
                headers: { 'Content-Type': 'application/json' },
                body: JSON.stringify({ name, priority })
            });
            const data = await res.json();

            if (data.status === 'success') {
                // Reset form
                taskNameInput.value = '';
                taskPriorityInput.value = '';
                // Update UI
                updateUI();
            } else {
                alert('Error adding task: ' + data.message);
            }
        } catch (err) {
            console.error(err);
            alert('Failed to connect to backend.');
        }
    }
});

// Event Listener: Complete Task
completeBtn.addEventListener('click', async () => {
    try {
        const res = await fetch(`${API_URL}/extract-max`, { method: 'POST' });
        const data = await res.json();

        if (data.status === 'success') {
            // alert(`Completed task: ${data.task.name}`);
            updateUI();
        } else {
            alert(data.message);
        }
    } catch (err) {
        console.error(err);
    }
});

/**
 * Updates the entire UI based on the current state of the Heap.
 */
async function updateUI() {
    await renderCurrentTask();
    await renderHeapVisualizer();
}

/**
 * Renders the highest priority task in the main card.
 */
async function renderCurrentTask() {
    try {
        const res = await fetch(`${API_URL}/peek`);
        const data = await res.json();

        if (data.status === 'success') {
            const topTask = data.task;

            // Determine color class based on priority
            let priorityClass = 'priority-low';
            if (topTask.priority >= 80) priorityClass = 'priority-high';
            else if (topTask.priority >= 40) priorityClass = 'priority-medium';

            currentTaskDisplay.innerHTML = `
                <div class="task-highlight">${topTask.name}</div>
                <span class="priority-badge ${priorityClass}">Priority: ${topTask.priority}</span>
            `;
            currentTaskDisplay.classList.remove('empty-state');
            completeBtn.disabled = false;
        } else {
            currentTaskDisplay.innerHTML = 'No tasks pending. Time to relax.';
            currentTaskDisplay.classList.add('empty-state');
            completeBtn.disabled = true;
        }
    } catch (err) {
        currentTaskDisplay.innerHTML = 'Error connecting to server.';
        completeBtn.disabled = true;
    }
}

/**
 * Renders the internal array of the heap to visualize the structure.
 */
async function renderHeapVisualizer() {
    try {
        const res = await fetch(`${API_URL}/all`);
        const data = await res.json();

        heapVisualizer.innerHTML = '';

        if (data.status === 'success' && data.heap) {
            data.heap.forEach((task) => {
                const node = document.createElement('div');
                node.className = 'heap-node';
                node.innerHTML = `
                    <span class="node-priority">${task.priority}</span>
                    <span class="node-name">${task.name}</span>
                `;
                heapVisualizer.appendChild(node);
            });
        }
    } catch (err) {
        console.error(err);
    }
}

// Initial Render
updateUI();
