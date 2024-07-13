# Starting and Stopping Services in Ubuntu

### Check if a service is already running

```bash
sudo systemctl status <program>
# or
sudo service <program> status
```

### Run a service

```bash
sudo systemctl start <program>
# or
sudo service <program> start
```

### Stop a service

```bash
sudo systemctl stop <program>
# or
sudo service <program> stop
```

### Auto-start a service at startup

```
sudo systemctl enable <program>
```

### Disable auto-start a service at startup

```
sudo systemctl disable <program>
```
