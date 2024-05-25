.text

.global mtMAS0
.global mtMAS1
.global mtMAS2
.global mtMAS3 

.align 4
  
mtMAS0:
 mtspr 624,r3
 blr
mtMAS1:
 mtspr 625,r3
 blr
mtMAS2:
 mtspr 626,r3
 blr
mtMAS3:
 mtspr 627,r3
 blr
 

.end


