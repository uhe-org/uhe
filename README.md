# uhe

A Rainmeter suite with a simple duotone design.

Supports light/dark mode:

![Desktop-Light](assets/desktop-light.jpg#gh-light-mode-only)
![Desktop-Dark](assets/desktop-dark.jpg#gh-dark-mode-only)

*Wallpaper source (Wallpaper Engine): [White Oak (Day/Night)](https://steamcommunity.com/sharedfiles/filedetails/?id=2911866381)*\
*Layout: "uhe Default Layout"*

## Extensions

There are skins developed in other repositories with the same aesthetic.

- To-Do List: https://github.com/uhe-org/uhe-todo-list
- osu! extension: https://github.com/uhe-org/uhe-osu-extension

## Dependencies

Some skins rely on external plugins / software. All Rainmeter plugins listed below are packaged in the `.rmskin`.

- CustomTaskbar (Windows 10+)
    - TranslucentTaskbar ([Rainmeter Forums](https://forum.rainmeter.net/viewtopic.php?t=24879)) ([DeviantArt](https://www.deviantart.com/arkenthera/art/TranslucentTaskbar-1-2-656402039)) ([GitHub Gist](https://gist.github.com/0x61726b/7a807e04ee8f1d95425f710944667508))
        - Not currently compatible with Windows 11 22H2 and above, use TranslucentTB instead.
    - [TranslucentTB (app)](https://github.com/TranslucentTB/TranslucentTB)
- KeyCounter
    - HotKey ([Rainmeter Forums](https://forum.rainmeter.net/viewtopic.php?t=18849)) ([GitHub Repo](https://github.com/brianferguson/HotKey.dll))
- NowPlaying (Web)
    - WebNowPlaying ([Rainmeter Forums](https://forum.rainmeter.net/viewtopic.php?f=127&t=26619)) ([GitHub Repo](https://github.com/keifufu/WebNowPlaying-Redux-Rainmeter))
- Lyrics Display
    - Mouse ([Rainmeter Forums](https://forum.rainmeter.net/viewtopic.php?t=26030)) ([GitHub Repo](https://github.com/NighthawkSLO/Mouse.dll))

## Development

This repo is structured in a way to automate releases, but there is no way to have multiple custom skins folders in Rainmeter. It makes developing in real time not possible by default, and symlinking has to be done. For example in PowerShell as admin:

```powershell
New-Item -Path "$([Environment]::GetFolderPath("MyDocuments"))\Rainmeter\Skins\uhe" -ItemType SymbolicLink -Value "$([Environment]::GetFolderPath("MyDocuments"))\GitHub\uhe\RMSKIN\Skins\uhe"
```

## License

Licensed under the MIT License.
