# CS2 Bunny Hop Hack – COMP6841 Project

This project is part of my COMP6841 coursework at UNSW, exploring how memory manipulation techniques can be used to implement simple game cheats. Specifically, this is a Python-based bunny hop (auto-jump) hack for **Counter-Strike 2**, implemented using the `pymem` library.

The project helped me understand how game memory is structured, how offsets can be used to interact with game logic, and how anti-cheat systems try to detect or prevent this kind of manipulation.

---

## 🎮 What It Does

This script automates bunny hopping in CS2 by:

- Attaching to the `cs2.exe` process
- Finding the player object using memory offsets
- Reading a bitflag to determine if the player is on the ground
- Writing to the `dwForceJump` memory address to simulate a jump

As long as the SPACE key is held and the player is on the ground, the script triggers the jump action repeatedly.

---

## ⚙️ How to Use

### ⚠️ Ethical Use Only

> This tool was developed **strictly for educational purposes** as part of a university project. It should **only** be used in **offline matches with bots**. Do **not** use this on public servers or in online multiplayer.

### ✅ Prerequisites

- Python 3.x
- `pymem` and `keyboard` Python libraries
- Counter-Strike 2 (running)
- The correct memory offsets for your current game version

### 📦 Installation

1. Clone this repository or download `bhop_cs2.py`
2. Open a terminal and install the required libraries:

```bash
pip install pymem keyboard
```

3. Launch CS2 and enter a private bot match
4. Run the script:

```bash
python bhop_cs2.py
```

5. Hold the SPACE key in-game to auto bunny hop.

---

## 🧠 Offsets

These offsets are version-specific and **may break** when CS2 updates. Make sure you update them regularly.

```python
dwLocalPlayerPawn = 0x16C18F8
m_fFlags = 0x3F0
dwForceJump = 0x173D870
```

You can find current offsets from:
- 📌 [a2x/cs2-dumper GitHub repo](https://github.com/a2x/cs2-dumper/blob/main/output/offsets.json)

Alternatively, use Cheat Engine to scan for addresses manually — although this is more advanced and noisy (I tried scanning for health and team number but got overwhelming results,  still useful for understanding pointer paths and what memory looks like).

---

## 📁 Project Structure

```
bhop_cs2.py         # Python script for auto bunny hopping
README.md           # Project explanation and usage guide
```

---

## 📚 What I Learned

This project helped me develop a working understanding of:

- How memory manipulation can affect live game processes
- The structure of game clients and how values like position, flags, and actions are stored in memory
- Using Cheat Engine for manual offset discovery (and why it's hard!)
- The value of GitHub open-source tooling (like offset dumpers)
- How anti-cheat systems rely on detection of known behaviors or signatures

It also reinforced important lessons about the ethics of software security:
- Even simple hacks like this expose how vulnerable many games are
- Anti-cheat software is a constant arms race
- Responsible disclosure and sandboxing (e.g. using bots, offline) are essential for ethical research

---


## 🧾 C++ Attempt (CS:GO Version)

Before switching to Python and CS2, I initially attempted to create a bunny hop hack for the original **CS:GO** using C++ and the Windows API and watching youtube tutorials.

### 🗂️ Files

You can find these files in the `csgo_bhop_cpp/` folder:

- `main.cpp` – Bunny hop logic
- `memory.cpp` / `memory.h` – A reusable Memory class using Windows API (e.g. `OpenProcess`, `ReadProcessMemory`, `WriteProcessMemory`)

### 📌 Why It Was Abandoned

After building and debugging the code in Visual Studio, I discovered that **CS:GO was deprecated in 2023** and could no longer be installed or launched through Steam. As a result, I was unable to test or use this version of the hack.

However, writing this code taught me:

- How to use Windows API for process access
- How to search for and write memory values in C++
- How to structure a modular memory hacking framework
- The complexity of using lower-level languages for direct memory access

This experience gave me foundational knowledge I later applied in Python when targeting **CS2**, which has a more active player base and current memory offsets available.


## 📌 Disclaimer

This project is for **educational purposes only** and should never be used to disrupt public servers or gain unfair advantages in competitive play. Doing so violates both **game terms of service** and basic ethical principles.

---

## 🧪 Credits

Inspired by YouTube tutorials, GitHub offset dumpers, Cheat Engine guides, and official CS2 documentation.
Bunny Hop Hack can be seen working in my video.