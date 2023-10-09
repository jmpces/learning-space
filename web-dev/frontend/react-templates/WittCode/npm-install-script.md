# A React environment template
This is based on [**WittCode's video**](https://www.youtube.com/watch?v=h3LpsM42s5o&t=76s), a minimal react environment setup.

## Install Setup

```
npm init -y
npm i react react-dom
npm i -D @babel/core @babel/preset-env @babel/preset-react babel-loader
npm i -D html-webpack-plugin webpack webpack-cli webpack-dev-server

```

## package.json scripts
```
"start": "webpack-dev-server --mode development --open --hot",
"build": "webpack --mode production"
```