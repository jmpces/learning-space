## Install Pandoc

```bash
sudo apt-get install pandoc texlive-latex-base texlive-latex-recommended texlive-latex-extra
```

## Convert A Markdown File to PDF

```bash
pandoc file.md -s -o file.pdf
```

## Convert All Markdown File to One PDF

```bash
pandoc *.md -s -o merged.pdf
```

## Example

```bash
pandoc -V geometry:margin=1.5in -s -o output-filename.pdf --from=markdown+grid_tables *.md
```
