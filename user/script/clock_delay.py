#!/usr/bin/env python3
"""
Pre-build script: ensure CyDelay(20) exists before Cy_SysClk_Dpll_Lp0_Init()
in the generated system config file.
"""

import os
import sys

# Locate the project root (one level up from user/script/)
SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
PROJECT_ROOT = os.path.dirname(os.path.dirname(SCRIPT_DIR))
TARGET_FILE = os.path.join(
    PROJECT_ROOT,
    "bsps", "TARGET_car_str_board", "config", "GeneratedSource", "cycfg_system.c"
)
TARGET_LINE = "Cy_SysClk_Dpll_Lp0_Init();"
INSERT_LINE = "    CyDelay(20);\n"


def main():
    if not os.path.exists(TARGET_FILE):
        print(f"[clock_delay] Target file not found: {TARGET_FILE}")
        sys.exit(0)

    with open(TARGET_FILE, "r") as f:
        lines = f.readlines()

    # Find the line index of Cy_SysClk_Dpll_Lp0_Init();
    target_idx = None
    for i, line in enumerate(lines):
        if TARGET_LINE in line:
            target_idx = i
            break

    if target_idx is None:
        print("[clock_delay] Cy_SysClk_Dpll_Lp0_Init() not found, skipping.")
        sys.exit(0)

    # Check if CyDelay(20) already exists within the previous ~10 lines
    search_start = max(0, target_idx - 10)
    for line in lines[search_start:target_idx]:
        if "CyDelay(5)" in line:
            print("[clock_delay] CyDelay(20) already present, nothing to do.")
            sys.exit(0)

    # Not found — insert it just before the target line
    print("[clock_delay] Inserting CyDelay(20) before Cy_SysClk_Dpll_Lp0_Init()...")
    lines.insert(target_idx, INSERT_LINE)

    with open(TARGET_FILE, "w") as f:
        f.writelines(lines)

    print("[clock_delay] Done.")


if __name__ == "__main__":
    main()
