# Minimal environment setup for unity game development using VScode.

## Windows Platform

This setup assumes you already have VScode in your machine.

1. Install **Unity Hub**
2. Create an account in **Unity Hub** then login
3. Install a **Unity Editor** version in **Unity Hub**
4. Install **.NET SDK** (v6.0.0)
5. Install **.NET Framework Developer Pack** (v1.7.4)
6. Install **MSBuild Tools** (Build Tools for Visual Studio 2022)
7. Create a project in **Unity Hub** then open it with your prefered **Unity Editor** version.
8. Open VScode then install the latest version of **C# Extension** written by _Microsoft_ (remember the version of the extension).
9. In VScode again, press `Ctrl` + `,`, then search for the text ***use modern net***, then disable/uncheck the `omnisharp: use Moder Net` option.
10. In **Unity Editor** navigate > `Window` > `Package Manager` > then check if the `Visual Studio Code Editor` was checked.
    - The `Visual Studio Code Editor`'s version should match the **C# Extension** version installed in step (8.)
    - If not installed(checked) add it by selecting the `Visual Studio Code Editor` item then click `Install`.
    - You can also select a specific version to be `Install`ed when necessary.
11. In **Unity Editor** navigate > `Edit` > `Preferences` > `External Tools` > set **External Scripting Editor** to `Visual Studio Code` > `Reset argument` > `Regenerate project files`
