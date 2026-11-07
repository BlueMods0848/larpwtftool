# LARP.WTF Tool

LARP.WTF is a Windows command-line utility with a simple interactive menu. It currently provides:

- **Nonce generation** — submits the supplied FRL token and app ID to the Oculus Graph API to authenticate the application and request a user nonce.
- **Discord webhook messaging** — sends a message through a Discord webhook URL you provide. Messages are sent at 500 ms intervals.
- **PlayFab `LoginWithCustomID`** — shown in the menu, but not implemented yet.

## Requirements

- Windows (the application uses the Windows console API)
- Visual Studio with the C++ workload and x64 build tools
- CMake 3.20 or newer

The repository includes the OpenSSL headers, libraries, and runtime DLLs used by the build.

## Build

From the repository folder, run:

```bat
compile.bat
```

The script configures and builds the x64 Debug target with CMake. The executable is created at `build\Debug\larpwtf.exe`; the required OpenSSL DLLs are copied alongside it.

To configure and build manually:

```bat
cmake -S . -B build -A x64
cmake --build build --config Debug
```

## Use

Run `build\Debug\larpwtf.exe` and choose an option from the menu:

1. **Generate Nonce** — enter your FRL token and the game's app ID. The tool requests application authentication and then a nonce. Keep tokens private; only use credentials and app IDs you are authorized to use.
2. **Send Webhook** — enter a Discord webhook URL, a message, and the number of messages to send. Only use webhooks you own or have permission to use, and choose a modest amount that complies with Discord's rules and rate limits. Treat the webhook URL as a secret; anyone with it may be able to post through it.
3. **PlayFab loginwithcustomid** — currently a placeholder; no login is performed.
4. **Exit** — closes the program.

The program requires an internet connection for nonce generation and webhook delivery. An unsuccessful request may not return a useful result; check that the credentials, app ID, or webhook are valid and that the service is reachable.

## Support

Join the [Discord server](https://discord.gg/zx6hmtRe5T).
