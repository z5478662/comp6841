import pymem
import pymem.process
import keyboard
import time

dwForceJump = 0x1851DF0
dwLocalPlayerPawn = 25530576 
client_module = "client.dll"

print("[*] Starting Bunny Hop...")

# Attach to cs2.exe process
try:
    pm = pymem.Pymem("cs2.exe")
    client = pymem.process.module_from_name(pm.process_handle, client_module).lpBaseOfDll
    print("[+] Attached to cs2.exe")
except Exception as e:
    print("[-] Failed to attach to CS2:", e)
    exit()

while True:
    try:
        if keyboard.is_pressed("space"):
            # Read LocalPlayerPawn
            local_player = pm.read_uint(client + dwLocalPlayerPawn)
            if local_player:
                pm.write_int(client + dwForceJump, 65537)  # Jump command
                time.sleep(0.01)
                pm.write_int(client + dwForceJump, 256)    # Release jump
        time.sleep(0.001)
    except KeyboardInterrupt:
        print("\n[*] Stopping script...")
        break
    except Exception as e:
        print("[-] Error:", e)
        time.sleep(1)