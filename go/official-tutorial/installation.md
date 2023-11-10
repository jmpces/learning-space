# Go Installation

Install the latest go version here https://go.dev/doc/install

```bash
# Delete previous go installation then extract the downloaded go version
rm -rf /usr/local/go
tar -C /usr/local -xzf go<MAJOR>.<MINOR>.<PATCH>.linux-amd64.tar.gz

# Add the go path installation to your environment variables
echo 'export PATH="$PATH:/usr/local/go/bin"' >> ~/.bashrc

# Add go command path installation to your environment variables
echo 'export PATH="$PATH:$HOME/go/bin"' >> ~/.bashrc
```

Then you might need to close the terminal then open it again to refresh the paths in the environment variables, if this does not work you might need to logout then login back to your computer or completely restart the computer for it to work.

```bash
# install latest go tool commands like :
# tour - local served quick tutorial by examples
# godoc - local served go module documentation
go install golang.org/x/tools/cmd/...@latest
```

# Go `tour`

Run the tour command in the command line to open the go tour tutorial

```bash
tour
```

# Go `godoc` Documentation

Run the `godoc` command to open the locally served offline go documentation.

```bash
godoc -http=:6060
```

Open it using your browser at

```bash
http://127.0.0.1:6060/pkg/
```

# Update Go Modules

```bash
go get -u
go mod tidy
```

to recursively update packages in any subdirectories:

```bash
go get -u ./...
```