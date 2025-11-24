import express from 'express';
import { spawn } from 'child_process';
import cors from 'cors';
import bodyParser from 'body-parser';
import path from 'path';
import { fileURLToPath } from 'url';

const __filename = fileURLToPath(import.meta.url);
const __dirname = path.dirname(__filename);

const app = express();
const PORT = 3000;

app.use(cors());
app.use(bodyParser.json());
app.use(express.static('.')); // Serve static files for the frontend

// Spawn the C process
const cProcess = spawn('./priority_queue');

cProcess.stdout.on('data', (data) => {
    console.log(`C Output: ${data}`);
});

cProcess.stderr.on('data', (data) => {
    console.error(`C Error: ${data}`);
});

// Helper to send command to C and wait for JSON response
function sendCommand(command) {
    return new Promise((resolve, reject) => {
        // We need to attach a one-time listener for the response
        const listener = (data) => {
            const str = data.toString().trim();
            // The C program might send multiple lines or partial chunks. 
            // For this simple project, we assume 1 command = 1 JSON line response.
            try {
                const json = JSON.parse(str);
                cProcess.stdout.removeListener('data', listener);
                resolve(json);
            } catch (e) {
                // If not valid JSON, it might be debug output, ignore or log
                // console.log("Non-JSON output:", str);
            }
        };

        cProcess.stdout.on('data', listener);
        cProcess.stdin.write(command + '\n');
    });
}

// API Endpoints

app.post('/add-task', async (req, res) => {
    const { name, priority } = req.body;
    // Sanitize name to remove spaces if needed, or handle in C. 
    // Our C code expects "INSERT name priority".
    // Let's replace spaces with underscores for safety in this simple protocol
    const safeName = name.replace(/\s+/g, '_');

    try {
        const response = await sendCommand(`INSERT ${safeName} ${priority}`);
        res.json(response);
    } catch (e) {
        res.status(500).json({ error: e.message });
    }
});

app.post('/extract-max', async (req, res) => {
    try {
        const response = await sendCommand('EXTRACT');
        res.json(response);
    } catch (e) {
        res.status(500).json({ error: e.message });
    }
});

app.get('/peek', async (req, res) => {
    try {
        const response = await sendCommand('PEEK');
        res.json(response);
    } catch (e) {
        res.status(500).json({ error: e.message });
    }
});

app.get('/all', async (req, res) => {
    try {
        const response = await sendCommand('PRINT');
        res.json(response);
    } catch (e) {
        res.status(500).json({ error: e.message });
    }
});

app.listen(PORT, () => {
    console.log(`Server running at http://localhost:${PORT}`);
});
