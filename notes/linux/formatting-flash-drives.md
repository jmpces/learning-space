# find your flash drive

get the name of last leaf of the tree, usually `sdb1`

```shell
lsblk
```

# unmount it

```shell
sudo umount /dev/sdb1
```

# format using FAT 32

```shell
sudo mkfs.vfat -F 32 /dev/sdy1
```

# format using NTFS

```shell
sudo mkfs.ntfs /dev/sdb1
```

# eject after

```shell
sudo eject /dev/sdb1
```
