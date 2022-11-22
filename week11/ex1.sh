fallocate -l 50MiB lofs.img
sudo losetup -f lofs.img
sudo mkfs.ext4 /dev/loop0
mkdir -p lofsdisk
sudo mount /dev/loop0 lofsdisk
