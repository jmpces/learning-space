# Dot Net Maui Setup With Physical Device

## Install dotnet For - .NET (MAUI)

```bash
wget https://dot.net/v1/dotnet-install.sh -O dotnet-install.sh
chmod +x ./dotnet-install.sh
```

You might need to add the `.dotnet` path where it was installed manually to your environment variables

## Add to Environment Variables

```bash
export DOTNET_ROOT="$HOME/.dotnet"
export PATH="$PATH:$DOTNET_ROOT:$DOTNET_ROOT/tools"
```

## Install .NET MAUI

```bash
dotnet workload install maui-android

# view the workload list, it should show maui-android
dotnet workload list
```

## Install MS OpenJDK 11

```bash
ubuntu_release=`lsb_release -rs`
wget https://packages.microsoft.com/config/ubuntu/${ubuntu_release}/packages-microsoft-prod.deb -O packages-microsoft-prod.deb
sudo dpkg -i packages-microsoft-prod.deb

sudo apt-get install apt-transport-https
sudo apt-get update
sudo apt-get install msopenjdk-11
```

## Create a MAUI app in visual studio code

1. Open VS Code
2. You should have `C# Dev Kit` dev kit installed (if not install it)
3. Install `.NET MAUI` exension
4. Sign-in with microsoft email and activate licence with `C# Dev Kit`
5. Restart VS Code and it should have an option in welcome tab to create a MAUI app
6. Create MAUI App and edit the `.csproj` file with:

    ```xml
    <TargetFrameworks>net8.0-android</TargetFrameworks>
    <TargetFrameworks Condition="!$([MSBuild]::IsOSPlatform('linux'))">$(TargetFrameworks);net8.0-ios;net8.0-maccatalyst</TargetFrameworks>
    <TargetFrameworks Condition="$([MSBuild]::IsOSPlatform('windows'))">$(TargetFrameworks);net8.0-windows10.0.19041.0</TargetFrameworks>
    ```

## You need to have android studio as well
- It should have all the android SKDs for different android versions you want to support
- VS Code should prompt you to find the `Android/Sdk` folder in your device

## Pair with your android physical device

Note: use the `adb` in `Android/Sdk/platform-tools`

1. Enable developer mode, usb debugging and wireless debuggin.

2. Open wireless debugging and press the `pair with pairing code`

```bash
./adb pair <pairing-ip>:<pairing-port>
./adb pair <wireless-debugging-ip>:<and-port>
```

The first command uses the ip address and port shown when you clicked the `pair with pairing code`.

While the second command uses the ip address you will immediately see when you enter the `wireless debugging`.

## Run MAUI app in android device

1. click the `{}` in VS Code
2. pin the `Android (build)` - it should show your android device after
3. click `Run and Debug`