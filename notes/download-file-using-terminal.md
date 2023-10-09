# Downloading Files Using Terminal

### Using Wget

filename will be saved as it is

```bash
wget DIRECT_LINK_OF_FILE
```

set a new filename

```bash
wget -cO - DIRECT_LINK_OF_FILE > SAVE_AS_FILENAME
```

### Using Curl

```bash
curl <https-file-download-url> -o <new-file-name> -L
```
