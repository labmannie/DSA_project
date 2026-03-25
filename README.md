<div align="center">

<!-- ═══════════════════════════════════════════════════════════════ -->
<!--                  🌟 HERO HEADER — WAVING GRADIENT              -->
<!-- ═══════════════════════════════════════════════════════════════ -->
<img src="https://capsule-render.vercel.app/api?type=waving&color=gradient&customColorList=0,2,2,5,30&height=280&section=header&text=LAB_MANNIE_OS&fontSize=80&fontAlignY=38&fontColor=00FFCC&desc=ULTIMATE%20TASK%20MANAGER%20v1.0&descAlignY=58&descAlign=50&descSize=22&animation=twinkling&stroke=00FFCC&strokeWidth=2" width="100%"/>

<br>

<!-- ═══════════════════════════════════════════════════════════════ -->
<!--             💻 HACKER BOOT SEQUENCE — TYPING ANIMATION         -->
<!-- ═══════════════════════════════════════════════════════════════ -->
<a href="https://github.com/LabMannie">
  <img src="https://readme-typing-svg.herokuapp.com?font=Share+Tech+Mono&weight=800&size=22&pause=600&color=00FFCC&center=true&vCenter=true&width=860&height=55&lines=%5BBOOT%5D+Initializing+LAB_MANNIE+Core+OS...;%5BSYS%5D+Allocating+Dynamic+Memory+Pools...;%5BNET%5D+Establishing+Neural+Priority+Queue...;%5BSEC%5D+Encrypting+Memory+Blocks...;%5BALGO%5D+Sorting+Engine+Online+%E2%80%94+O(1)+Ready...;%5B%E2%9C%93%5D+ALL+SYSTEMS+100%25+OPERATIONAL+%F0%9F%9F%A2" alt="Typing SVG" />
</a>

<br><br>

<!-- ═══════════════════════════════════════════════════════════════ -->
<!--                    🛡️ ELITE STATUS BADGES                      -->
<!-- ═══════════════════════════════════════════════════════════════ -->
[![Architect](https://img.shields.io/badge/%E2%96%A0%20ARCHITECT-LAB__MANNIE-FF0055?style=for-the-badge&logo=codeforces&logoColor=white)](https://github.com/LabMannie)
[![Language](https://img.shields.io/badge/%E2%96%A0%20CORE-PURE_C-00599C?style=for-the-badge&logo=c&logoColor=white)](#)
[![Algorithm](https://img.shields.io/badge/%E2%96%A0%20ALGO-O(1)_DEQUEUE-00FFCC?style=for-the-badge&logo=aerospike&logoColor=black)](#)
[![UI](https://img.shields.io/badge/%E2%96%A0%20INTERFACE-ANSI_CYBERPUNK-9D00FF?style=for-the-badge&logo=gnometerminal&logoColor=white)](#)
[![License](https://img.shields.io/badge/%E2%96%A0%20LICENSE-MIT-FFD700?style=for-the-badge&logo=opensourceinitiative&logoColor=black)](#)

<br>

<!-- ═══════════════════════════════════════════════════════════════ -->
<!--               🔥 ANIMATED METRICS / STATS ROW                  -->
<!-- ═══════════════════════════════════════════════════════════════ -->
![Lines of Code](https://img.shields.io/badge/LINES_OF_CODE-∞-00FFCC?style=flat-square&labelColor=0d0d0d)
![Memory Leaks](https://img.shields.io/badge/MEMORY_LEAKS-ZERO-FF0055?style=flat-square&labelColor=0d0d0d)
![Complexity](https://img.shields.io/badge/DEQUEUE_COMPLEXITY-O(1)-9D00FF?style=flat-square&labelColor=0d0d0d)
![Build](https://img.shields.io/badge/BUILD-PASSING-00FF88?style=flat-square&labelColor=0d0d0d&logo=github-actions&logoColor=white)

<br>

> 🌌 *"Where others write code, I engineer digital physics.*
> *Efficiency is not an option — it is the baseline."*
>
> **— LAB MANNIE**

</div>

---

<!-- ═══════════════════════════════════════════════════════════════ -->
<!--                     💠 CORE DIRECTIVE                          -->
<!-- ═══════════════════════════════════════════════════════════════ -->

## 💠 THE CORE DIRECTIVE

<img align="right" src="https://readme-typing-svg.herokuapp.com?font=Share+Tech+Mono&size=13&pause=900&color=9D00FF&center=false&vCenter=true&width=300&height=120&lines=%3E+Linked+List+Core...+%5BOK%5D;%3E+Priority+Engine...+%5BOK%5D;%3E+ANSI+Renderer...+%5BOK%5D;%3E+Memory+Guard...+%5BOK%5D;%3E+Task+Queue...+%5BREADY%5D" />

Welcome to the absolute pinnacle of Command Line interfaces. Engineered entirely from scratch by **LabMannie**, this system completely bypasses bloated modern frameworks to deliver a **hyper-optimized, dynamically-allocated Priority Queue**.

This is not a simple to-do list. This is a **Task Execution Engine** built on a mathematically sorted **Singly Linked List**, enclosed within a visually stunning ANSI-powered Control Deck.

**Every nanosecond. Every allocation. Every decision.** Ruthlessly optimized.

<br clear="right"/>

---

<!-- ═══════════════════════════════════════════════════════════════ -->
<!--               ⚡ ARCHITECTURAL SUPERSTRUCTURE                  -->
<!-- ═══════════════════════════════════════════════════════════════ -->

## ⚡ ARCHITECTURAL SUPERSTRUCTURE — L-PQ ENGINE

```mermaid
%%{init: {'theme': 'dark', 'themeVariables': { 'primaryColor': '#1e1e1e', 'primaryTextColor': '#00FFCC', 'primaryBorderColor': '#00FFCC', 'lineColor': '#FF0055', 'secondaryColor': '#0d0d0d', 'tertiaryColor': '#1a1a2e'}}}%%
graph TD
    A["🗃️ USER INPUT<br/>Task Title + Priority Value"] -->|"Trigger → ENQUEUE"| B

    B{"⚡ LAB_MANNIE<br/>CORE ENGINE"}

    B -->|"Priority Check"| C{"Is list empty<br/>OR new priority > HEAD?"}

    C -->|"✅  YES"| D["🔗 BIND TO HEAD<br/>Complexity: O(1)"]
    C -->|"🔍  NO"| E["🔎 TRAVERSE & INJECT<br/>Complexity: O(N)"]

    D --> F(["🎯 DEQUEUE<br/>Execute Highest Priority<br/>O(1) — INSTANT"])
    E --> F

    F --> G["🧹 FREE NODE<br/>malloc → free<br/>Zero Leak Protocol"]

    style A fill:#1e1e1e,stroke:#00FFCC,stroke-width:2px,color:#00FFCC
    style B fill:#FF0055,stroke:#fff,stroke-width:3px,color:#fff
    style C fill:#1a1a2e,stroke:#9D00FF,stroke-width:2px,color:#c0c0ff
    style D fill:#003333,stroke:#00FFCC,stroke-width:2px,color:#00FFCC
    style E fill:#001a33,stroke:#00599C,stroke-width:2px,color:#66b3ff
    style F fill:#2a003a,stroke:#9D00FF,stroke-width:3px,color:#cc88ff
    style G fill:#1e1e1e,stroke:#FF0055,stroke-width:2px,color:#ff6688
```

---

<!-- ═══════════════════════════════════════════════════════════════ -->
<!--                  💎 TECHNICAL SPECIFICATIONS                   -->
<!-- ═══════════════════════════════════════════════════════════════ -->

## 💎 ELITE CAPABILITIES

<details open>
<summary><b>🔥 Click to Expand Full Technical Specifications</b></summary>

<br>

| MODULE | SPECIFICATION | COMPLEXITY | IMPACT |
| :---: | :--- | :---: | :--- |
| 🧠 **Neural Sorting** | Auto-Descending Priority Algorithm | `O(N)` insert | Highest task always at head — zero guesswork |
| ⚡ **Instant Dequeue** | Head-pointer extraction + `free()` | `O(1)` | Execute critical objective in nanoseconds |
| 🌈 **ANSI UI Engine** | Hardcoded Escape Sequences + box-drawing | `O(N)` render | Pixel-perfect cyberpunk aesthetics, zero latency |
| 🛡️ **Ironclad Memory** | Dynamic `malloc()` paired with `free()` | `O(1)` | Absolutely zero memory leaks. Valgrind-clean |
| ⚙️ **Strict Validation** | Boundary enforcement `[1–100]` | `O(1)` | Prevents buffer overflows + logic corruption |
| 🖥️ **Diagnostic Mode** | Full queue render with ANSI borders | `O(N)` | Complete pipeline visibility at any moment |

</details>

---

<!-- ═══════════════════════════════════════════════════════════════ -->
<!--                🚀 DEPLOYMENT PROTOCOL                         -->
<!-- ═══════════════════════════════════════════════════════════════ -->

## 🚀 DEPLOYMENT PROTOCOL

> ⚡ Get the engine running locally in under **10 seconds.**

**① CLONE THE REPOSITORY**
```bash
git clone https://github.com/LabMannie/lab-task-engine.git
cd lab-task-engine
```

**② COMPILE THE MATRIX**
```bash
# Requires GCC or Clang — any POSIX-compliant system
gcc main.c -o LabTaskEngine -O3 -Wall -Wextra
```

**③ IGNITE THE SYSTEM**
```bash
./LabTaskEngine
```

> 💡 *Tip: Use `-O3` for maximum compile-time optimization. The engine was built for it.*

---

<!-- ═══════════════════════════════════════════════════════════════ -->
<!--               🎮 MISSION CONTROL DECK                         -->
<!-- ═══════════════════════════════════════════════════════════════ -->

## 🎮 MISSION CONTROL DECK

Navigate the terminal using absolute precision.

| KEY | COMMAND | DESCRIPTION |
| :---: | :--- | :--- |
| `1` | **⚡ INJECT TASK** | Provide a Priority `[1–100]` + Title. L-PQ auto-sorts on insert. |
| `2` | **🎯 EXECUTE CRITICAL** | Fires the `O(1)` Dequeue algorithm. Destroys node + frees memory instantly. |
| `3` | **📡 SYSTEM DIAGNOSTIC** | Renders a neon-bordered ASCII table mapping the entire task pipeline. |
| `4` | **💀 TERMINATE** | Triggers total system shutdown + recursive memory wipe of all nodes. |

---

<!-- ═══════════════════════════════════════════════════════════════ -->
<!--               💻 VISUAL TELEMETRY                             -->
<!-- ═══════════════════════════════════════════════════════════════ -->

## 💻 LIVE VISUAL TELEMETRY

```
╔═══════════════════════════════════════════════════════════════════╗
║  [!] LAB_MANNIE OS — INTERFACE v1.0    [ SYSTEM: OPERATIONAL ]   ║
╠══════╦════════════╦═══════════════════════════════╦═════════════╣
║  ID  ║  PRIORITY  ║  TASK DESIGNATION             ║   STATUS    ║
╠══════╬════════════╬═══════════════════════════════╬═════════════╣
║  01  ║  [ 100 ]   ║  CRACK THE MAINFRAME           ║  ⚡ ACTIVE  ║
║  02  ║  [ 085 ]   ║  OPTIMIZE MEMORY POOL          ║  🔷 QUEUED  ║
║  03  ║  [ 070 ]   ║  REFACTOR NEURAL CORE          ║  🔷 QUEUED  ║
║  04  ║  [ 045 ]   ║  BENCHMARK DEQUEUE CYCLES      ║  ⏸ WAITING  ║
║  05  ║  [ 010 ]   ║  REST INITIATIVE               ║  💤 IDLE    ║
╚══════╩════════════╩═══════════════════════════════╩═════════════╝
   >> Memory Nodes Active: 5  |  Next Dequeue: ID-01 [PRIORITY 100]
   >> Awaiting Input Command: █
```

---

<!-- ═══════════════════════════════════════════════════════════════ -->
<!--             📊 GITHUB STATS — ANIMATED CARDS                   -->
<!-- ═══════════════════════════════════════════════════════════════ -->

## 📊 SYSTEM TELEMETRY — LIVE STATS

<div align="center">

<img height="180em" src="https://github-readme-stats.vercel.app/api?username=LabMannie&show_icons=true&theme=radical&include_all_commits=true&count_private=true&border_color=00FFCC&title_color=00FFCC&icon_color=FF0055&text_color=ffffff&bg_color=0d0d0d"/>

<img height="180em" src="https://github-readme-stats.vercel.app/api/top-langs/?username=LabMannie&layout=compact&langs_count=8&theme=radical&border_color=9D00FF&title_color=9D00FF&text_color=ffffff&bg_color=0d0d0d"/>

</div>

<div align="center">

<img src="https://github-readme-streak-stats.herokuapp.com/?user=LabMannie&theme=radical&background=0d0d0d&ring=FF0055&fire=FF0055&currStreakLabel=00FFCC&sideLabels=00FFCC&currStreakNum=ffffff&sideNums=ffffff&border=9D00FF" />

</div>

---

<!-- ═══════════════════════════════════════════════════════════════ -->
<!--              🐍 CONTRIBUTION SNAKE ANIMATION                   -->
<!-- ═══════════════════════════════════════════════════════════════ -->

## 🐍 COMMIT GRID — LIVE ACTIVITY PULSE

<div align="center">

<img src="https://raw.githubusercontent.com/LabMannie/LabMannie/output/github-contribution-grid-snake-dark.svg" alt="Snake animation" />

</div>

> *⚠️ To enable the snake: set up the [GitHub Actions workflow](https://github.com/Platane/snk) in your profile repo.*

---

<!-- ═══════════════════════════════════════════════════════════════ -->
<!--           📈 ACTIVITY GRAPH — ANIMATED WAVE                    -->
<!-- ═══════════════════════════════════════════════════════════════ -->

## 📈 NEURAL ACTIVITY GRAPH

<div align="center">

<img src="https://github-readme-activity-graph.vercel.app/graph?username=LabMannie&bg_color=0d0d0d&color=00FFCC&line=FF0055&point=9D00FF&area=true&area_color=9D00FF&hide_border=false&border_color=00FFCC&title_color=00FFCC" width="100%"/>

</div>

---

<!-- ═══════════════════════════════════════════════════════════════ -->
<!--                  👑 THE MASTERMIND                             -->
<!-- ═══════════════════════════════════════════════════════════════ -->

<div align="center">

## 👑 THE MASTERMIND

<img src="https://readme-typing-svg.herokuapp.com?font=Share+Tech+Mono&weight=900&size=42&pause=2000&color=FF0055&center=true&vCenter=true&width=620&height=90&lines=%E2%9C%A8+LAB+MANNIE+%E2%9C%A8" alt="Typing SVG" />

<img src="https://readme-typing-svg.herokuapp.com?font=Share+Tech+Mono&weight=700&size=16&pause=1500&color=9D00FF&center=true&vCenter=true&width=700&height=45&lines=%5B+SOLE+OWNER+%5D+%5B+LEAD+ENGINEER+%5D+%5B+UI+VISIONARY+%5D+%5B+MEMORY+ARCHITECT+%5D" alt="Roles SVG" />

<br>

*Every algorithm formulated, every memory block allocated,*
*and every pixel aligned was crafted exclusively by one entity.*

<br>

<!-- ═══════════════════════════════════════════════════════════════ -->
<!--                🏆 TROPHY SHOWCASE                              -->
<!-- ═══════════════════════════════════════════════════════════════ -->

<img src="https://github-profile-trophy.vercel.app/?username=LabMannie&theme=radical&no-frame=true&no-bg=true&row=1&column=7" width="100%" />

<br><br>

<!-- ═══════════════════════════════════════════════════════════════ -->
<!--              🏁 FOOTER ANIMATION — CLOSING BANNER              -->
<!-- ═══════════════════════════════════════════════════════════════ -->
<img src="https://capsule-render.vercel.app/api?type=waving&color=gradient&customColorList=0,2,2,5,30&height=140&section=footer&text=ENGINEERED+BY+LAB+MANNIE&fontSize=26&animation=fadeIn&fontColor=00FFCC&fontAlignY=65" width="100%"/>

</div>
