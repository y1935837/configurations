picom &
pipewire &
bash ~/etc/xroot.sh &
eval $(dbus-launch --sh-syntax --exit-with-session)
sudo ln -s /etc/sv/dbus /var/service/
hsetroot -cover ~/bg.jpg
xinput --set-prop "ROCCAT ROCCAT Kone Pro" "libinput Accel Speed" 0.15
