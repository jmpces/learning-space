# **Ubuntu**

- ## **Installing the SDK**

    [Link Reference](https://learn.microsoft.com/en-us/dotnet/core/install/linux-ubuntu#install-the-sdk)

    ```
    sudo apt-get update
    sudo apt-get install -y dotnet6
    ```

    ```
    sudo apt-get update &&
    sudo apt-get install -y dotnet-sdk-8.0
    ```

- ## **Installing only the Runtime**

    ```
    sudo apt-get update
    sudo apt-get install -y aspnetcore-runtime-6.0
    ```

    ```
    sudo apt-get update && \
    sudo apt-get install -y aspnetcore-runtime-8.0
    ```

# **Windows**

_n/a_

# Dependencies

When you install with a package manager, these libraries are installed for you. But, if you manually install .NET or you publish a self-contained app, you'll need to make sure these libraries are installed:

```
ca-certificates
libc6
libgcc-s1
libicu74
liblttng-ust1
libssl3
libstdc++6
libunwind8
zlib1g
```

example:
```
sudo apt install zlib1g
```
