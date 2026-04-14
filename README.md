# Simulation Lab

A curated collection of discrete-event and system simulation programs implemented in **C** and **GPSS** (General Purpose Simulation System).

## 📁 Contents

- **C Programs**: Discrete-event simulation implementations covering queuing systems, inventory management, and more.
- **GPSS Programs**: System simulation models demonstrating various behaviors and processes.

## 🚀 Getting Started

### Prerequisites
- GCC compiler (for C programs)
- GPSS World or compatible GPSS environment (for GPSS programs)

### Installation

```bash
git clone <repository-url>
cd Simulation-Lab
```

## ▶️ Running Programs

### C Programs

```bash
cd C_Programs
gcc simulation.c -o simulation -lm
./simulation
```

**Note**: If a `Makefile` exists, run `make` instead.

### GPSS Programs

1. Open GPSS World or your GPSS environment
2. Load the desired `.gps` file from the `GPSS/` folder
3. Execute the simulation to view the generated report

## 📚 Project Structure

```
Simulation-Lab/
├── C_Programs/
│   └── [simulation programs]
└── GPSS/
    └── [GPSS models]
```