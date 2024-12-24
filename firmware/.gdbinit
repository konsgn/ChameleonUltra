target extended-remote /dev/ttyACM0
mon sw
att 1
mon rtt
mon rtt status
# load objects/fullimage.hex
file objects/bootloader.out
file objects/application.out
define loada
  load objects/application.out
  file objects/bootloader.out
  file objects/application.out
end
