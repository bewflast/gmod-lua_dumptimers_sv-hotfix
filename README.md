# gmod-lua_dumptimers_sv-hotfix
remove exploited lua_dumptimers_sv concommand

# Usage

```hook.Add("InitPostEntity", "lua_dumptimers_sv remove", function() require("dumptimers_fix") end)```

# Compiling

You can download target binaries from [here](https://github.com/bewflast/gmod-lua_dumptimers_sv-hotfix/releases/tag/Latest)

If you wanna compile it by yourself, do some steps:

1) Clone: `git clone --recursive https://github.com/bewflast/gmod-lua_dumptimers_sv-hotfix.git`

2) Generate building system's files: (Linux)`cmake -B build` (Windows)`cmake -B build -A Win32`

3) Compile: (Linux)`cmake --build build`    (Windows)`cmake --build --config Release` (or --config Debug)

4) On Windows, compiled module is located at `build/bin/release` (or `build/bin/debug`), on Linux - at `build`
