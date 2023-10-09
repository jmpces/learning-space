# **Using dotnet in CLI**

[Microsoft's Official Documentation](https://learn.microsoft.com/en-us/dotnet/core/tools/dotnet)

These are my notes for dotnet 6.

## **My release build**

```
dotnet publish -p:PublishSingleFile=true -p:PublishTrimmed=true -r win-x64 --self-contained true -c release
```

## **Create dotnet `gitignore`**

```
dotnet new gitignore
```

## **Create a solution file**

This will create a new solution file in the current directory.

```
dotnet new sln
```

## **Create a project app with the `console` template**

This will create a basic console C# application in the current directory.

```
dotnet new console -o sampleApp
```

## **Create a project library with the `classlib` template**

This will create a library/module in the current directory.

```
dotnet new console -o sampleLib
```

## **Add projects to the solution file**

This will add the projects to the current solution file in the directory, the folder project `sampleApp` and `sampleLib` should also exist in the same directory as the solution file.

```
dotnet sln add sampleApp sampleLib
```

## **Add a package to the library project**

```
cd sampleLib
dotnet add package <Package Name>
```

## **Reference the library/module to the application**

```
cd sampleApp
dotnet add reference ../sampleLib/sampleLib.csproj
```

## **Build the application**

```
cd sampleApp
dotnet build
```

## **Run the application**

```
cd sampleApp
dotnet run
```

## **Clean the `build` outputs**

```
cd sampleApp
dotnet clean
```

## **Publish, Bundle or Compile the application into release or debug builds**

This will create a single debug build executable that can run on Windows x64 that has a dotnet6 runtime. (will not run on Windows that don't have the runtime)

```
dotnet publish -p:PublishSingleFile-true -r win-x64 --self-contained false
```