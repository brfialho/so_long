🌐 Available languages:
🇺🇸 English | 🇧🇷 [Português](README.pt.md)

---

*This project was created as part of the 42 curriculum by brfialho.*

---

# So Long - Square kingdom

This is a 2D tile-based game where you control a square. The objective is to collect all items on the map and then reach the exit.
The project is split into two versions. The basic one which handles player movement, collectibles, and exit conditions. The complete one, with additional gameplay and visual features

Complete version features include:
- Enemies with two behaviors: Green square which moves randomly, and the red one that actively follows the player
- Handcrafted pixel-by-pixel sprites and animations
- Dynamic move counter displayed on screen

## Usage

### Prerequisites

- **GCC** or **Clang** compiler
- **GNU Make**
- **X11 development libraries** (for Linux)

On Debian/Ubuntu systems, install dependencies:

```bash
sudo apt-get install libxext-dev libx11-dev
```

### Compilation

Clone the repository

```bash
git clone --recurse-submodule https://github.com/brfialho/so_long.git
cd so_long
```

For the basic version run

```bash
make
```

For the complete version run:

```bash
make bonus
```

### Available Make Commands

| Command       | Description                                      |
|---------------|--------------------------------------------------|
| `make`        | Compile the minimalist game version              |
| `make bonus`        | Compile the complete game version                |
| `make clean`  | Remove object files                              |
| `make fclean` | Remove object files and executable               |
| `make re`     | Recompile from scratch                           |

### Running the Program

Execute the compiled binary with a valid `.ber` map file:

#### Pre-made Maps

Basic version:
```bash
./so_long maps/mandatory_testing/valid2.ber
```
Complete version:
```bash
./so_long maps/levels/easy.ber
./so_long maps/levels/medium.ber
./so_long maps/levels/hard.ber
```

#### Building your own map

##### Rules

- The map file must end with `.ber`
- The map must be enclosed by walls
- The player must be able to reach all collectables and the exit
- The map must contain only the characters specified below

##### Syntax

- `1` - Walls
- `0` - Floor
- `P` - Player starting position
- `C` - Collectibles
- `E` - Exit
- `X` - Enemy (complete version only)

Example:

```
111111111111111111
1C010000000C0000C1
100001111100X00001
1P0011E00C0000C001
100C01000000000001
111111111111111111
```

### Controls

| Key     | Action |
|---------|--------|
| **W**   | Move Up |
| **A**   | Move Left |
| **S**   | Move Down  |
| **D**   | Move Right  |
| **ESC** | Exit Program |

---

# 🎮 Have fun and good luck with the hard map!
