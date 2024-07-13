# Compressing and Extracting Files in Terminal

### Tar Extraction (`Ubuntu`)

```bash
tar -xvzf tar-gz-file.tar.gz
```

### Unzip Extraction (`Ubuntu`)

```bash
unzip zip-file.zip -d ./
```

### Zip Compression (I used this in my `Ubuntu` specific projects)

```bash
zip zipped-file-name-output.zip file1 file2 ... fileN
```

### 7z Compression (I used this in my `Window` specific projects)

```bash
7z a -tzip zipped-file-name-output.zip file1 file2 ... fileN
```

### Zip Directory Compression (I used this in my `Ubuntu` specific projects)

```bash
zip -r zipped-directory-name-output.zip directory-to-zip
```

### 7z Directory Compression (I used this in my `Window` specific projects)

```bash
7z a -tzip zipped-directory-name-output.zip directory-to-zip
```
