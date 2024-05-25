.text

  .global GetTBL
  .global InitTB


  .equ TBU,285
  .equ TBL,284
  .equ TBLR,268
  .equ HID0,1008

.align 4
  
GetTBL:
   mfspr   r3, TBLR    
   blr

.align 4
   
InitTB:   
   xor     r3, r3, r3
   mtspr   TBL, r3
   mtspr   TBU, r3
   isync
   mfspr   r3, HID0
   ori     r3, r3, 0x4000
   isync
   mtspr   HID0, r3
   isync
   blr
       



.end


