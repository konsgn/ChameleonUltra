target extended-remote /dev/ttyACM0
file objects/bootloader.out
file objects/application.out
define staartt
  mon sw
  attach 1
#  mon rtt ram 0x20006000 0x20008000
#  mon rtt poll 100 10 15
#  mon rtt
#  mon rtt status
  continue
end
define loadup
  load objects/fullimage.hex
  file objects/bootloader.out
  file objects/application.out
end
