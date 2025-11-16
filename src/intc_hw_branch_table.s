# intc_hw_branch_table.s - INTC hardware vector mode branch table example
# Description: INTC vector branch table when using INTC in HW vector mode
#            **** NOTE **** ONLY 100 EXAMPLE VECTORS ARE IMPLEMENTED HERE
# Rev 1.0 Jul  2, 2007 S Mihalik  
# Rev 1.1 Aug 30 1007 SM - Made SwIrq4Handler, emiosCh0Handler .extern  
# Copyright Freescale Semiconductor, Inc. 2007. All rights reserved

.section .intc_hw_branch_table

  .extern eint0_handler 
  .extern eint6_handler
  .extern esci0_handler
  .extern esci1_handler

#.equ ALIGN_OFFSET, 2     # MPC551x:  4 byte branch alignments (Diab, GHS use 2, CodeWarrior 4)
.equ ALIGN_OFFSET, 16      # MPC555x: 16 byte branch alignments (Diab, GHS use 4, CodeWarrior 16)

IntcHandlerBranchTable:   # Only 100 example vectors are implemented here

           .align ALIGN_OFFSET 
hw_vect0:   b   hw_vect0        #INTC HW vector 0	
           .align ALIGN_OFFSET 
hw_vect1:   b   hw_vect1        #INTC HW vector 1	
           .align ALIGN_OFFSET 
hw_vect2:   b   hw_vect2        #INTC HW vector 2	
           .align ALIGN_OFFSET 
hw_vect3:   b   hw_vect3        #INTC HW vector 3	
           .align ALIGN_OFFSET 
hw_vect4:   b   hw_vect4        #INTC HW vector 4	
           .align ALIGN_OFFSET 
hw_vect5:   b   hw_vect5        #INTC HW vector 5	
           .align ALIGN_OFFSET 
hw_vect6:   b   hw_vect6        #INTC HW vector 6	
           .align ALIGN_OFFSET 
hw_vect7:   b   hw_vect7        #INTC HW vector 7	
           .align ALIGN_OFFSET 
hw_vect8:   b   hw_vect8        #INTC HW vector 8	
           .align ALIGN_OFFSET 
hw_vect9:   b   hw_vect9        #INTC HW vector 9	
           .align ALIGN_OFFSET 
hw_vect10:  b   hw_vect10       #INTC HW vector 10	
           .align ALIGN_OFFSET 
hw_vect11:  b   hw_vect11       #INTC HW vector 11	
           .align ALIGN_OFFSET 
hw_vect12:  b   hw_vect12       #INTC HW vector 12	
           .align ALIGN_OFFSET 
hw_vect13:  b   hw_vect13       #INTC HW vector 13	
           .align ALIGN_OFFSET 
hw_vect14:  b   hw_vect14       #INTC HW vector 14	
           .align ALIGN_OFFSET 
hw_vect15:  b   hw_vect15       #INTC HW vector 15	
           .align ALIGN_OFFSET 
hw_vect16:  b   hw_vect16       #INTC HW vector 16	
           .align ALIGN_OFFSET 
hw_vect17:  b   hw_vect17       #INTC HW vector 17	
           .align ALIGN_OFFSET 
hw_vect18:  b   hw_vect18       #INTC HW vector 18	
           .align ALIGN_OFFSET 
hw_vect19:  b   hw_vect19       #INTC HW vector 19	
           .align ALIGN_OFFSET 
hw_vect20:  b   hw_vect20       #INTC HW vector 20	
           .align ALIGN_OFFSET 
hw_vect21:  b   hw_vect21       #INTC HW vector 21	
           .align ALIGN_OFFSET 
hw_vect22:  b   hw_vect22       #INTC HW vector 22	
           .align ALIGN_OFFSET 
hw_vect23:  b   hw_vect23       #INTC HW vector 23	
           .align ALIGN_OFFSET 
hw_vect24:  b   hw_vect24       #INTC HW vector 24	
           .align ALIGN_OFFSET 
hw_vect25:  b   hw_vect25       #INTC HW vector 25	
           .align ALIGN_OFFSET 
hw_vect26:  b   hw_vect26       #INTC HW vector 26	
           .align ALIGN_OFFSET 
hw_vect27:  b   hw_vect27       #INTC HW vector 27	
           .align ALIGN_OFFSET 
hw_vect28:  b   hw_vect28       #INTC HW vector 28	
           .align ALIGN_OFFSET 
hw_vect29:  b   hw_vect29       #INTC HW vector 29	
           .align ALIGN_OFFSET 
hw_vect30:  b   hw_vect30       #INTC HW vector 30	
           .align ALIGN_OFFSET 
hw_vect31:  b   hw_vect31       #INTC HW vector 31	
           .align ALIGN_OFFSET 
hw_vect32:  b   hw_vect32       #INTC HW vector 32	
           .align ALIGN_OFFSET 
hw_vect33:  b   hw_vect33       #INTC HW vector 33	
           .align ALIGN_OFFSET 
hw_vect34:  b   hw_vect34       #INTC HW vector 34	
           .align ALIGN_OFFSET 
hw_vect35:  b   hw_vect35       #INTC HW vector 35	
           .align ALIGN_OFFSET 
hw_vect36:  b   hw_vect36       #INTC HW vector 36	
           .align ALIGN_OFFSET 
hw_vect37:  b   hw_vect37       #INTC HW vector 37	
           .align ALIGN_OFFSET 
hw_vect38:  b   hw_vect38       #INTC HW vector 38	
           .align ALIGN_OFFSET 
hw_vect39:  b   hw_vect39       #INTC HW vector 39	
           .align ALIGN_OFFSET 
hw_vect40:  b   hw_vect40       #INTC HW vector 40	
           .align ALIGN_OFFSET 
hw_vect41:  b   hw_vect41       #INTC HW vector 41	
           .align ALIGN_OFFSET 
hw_vect42:  b   hw_vect42       #INTC HW vector 42	
           .align ALIGN_OFFSET 
hw_vect43:  b   hw_vect43       #INTC HW vector 43	
           .align ALIGN_OFFSET 
hw_vect44:  b   hw_vect44       #INTC HW vector 44	
           .align ALIGN_OFFSET 
hw_vect45:  b   hw_vect45       #INTC HW vector 45	
           .align ALIGN_OFFSET 
hw_vect46:  b   eint0_handler   #INTC HW vector 46	
           .align ALIGN_OFFSET 
hw_vect47:  b   hw_vect47       #INTC HW vector 47	
           .align ALIGN_OFFSET 
hw_vect48:  b   hw_vect48       #INTC HW vector 48	
           .align ALIGN_OFFSET 
hw_vect49:  b   hw_vect49       #INTC HW vector 49	
           .align ALIGN_OFFSET 
hw_vect50:  b   eint6_handler   #INTC HW vector 50	
           .align ALIGN_OFFSET 
hw_vect51:  b   hw_vect51       #INTC HW vector 51	
           .align ALIGN_OFFSET 
hw_vect52:  b   hw_vect52       #INTC HW vector 52	
           .align ALIGN_OFFSET 
hw_vect53:  b   hw_vect53       #INTC HW vector 53	
           .align ALIGN_OFFSET 
hw_vect54:  b   hw_vect54       #INTC HW vector 54	
           .align ALIGN_OFFSET 
hw_vect55:  b   hw_vect55       #INTC HW vector 55	
           .align ALIGN_OFFSET 
hw_vect56:  b   hw_vect56       #INTC HW vector 56	
           .align ALIGN_OFFSET 
hw_vect57:  b   hw_vect57       #INTC HW vector 57	
           .align ALIGN_OFFSET 
hw_vect58:  b   hw_vect58       #INTC HW vector 58	
           .align ALIGN_OFFSET 
hw_vect59:  b   hw_vect59       #INTC HW vector 59	
           .align ALIGN_OFFSET 
hw_vect60:  b   hw_vect60       #INTC HW vector 60	
           .align ALIGN_OFFSET 
hw_vect61:  b   hw_vect61       #INTC HW vector 61	
           .align ALIGN_OFFSET 
hw_vect62:  b   hw_vect62       #INTC HW vector 62	
           .align ALIGN_OFFSET 
hw_vect63:  b   hw_vect63       #INTC HW vector 63	
           .align ALIGN_OFFSET 
hw_vect64:  b   hw_vect64       #INTC HW vector 64	
           .align ALIGN_OFFSET 
hw_vect65:  b   hw_vect65       #INTC HW vector 65	
           .align ALIGN_OFFSET 
hw_vect66:  b   hw_vect66       #INTC HW vector 66	
           .align ALIGN_OFFSET 
hw_vect67:  b   hw_vect67       #INTC HW vector 67	
           .align ALIGN_OFFSET 
hw_vect68:  b   hw_vect68       #INTC HW vector 68	
           .align ALIGN_OFFSET 
hw_vect69:  b   hw_vect69       #INTC HW vector 69	
           .align ALIGN_OFFSET 
hw_vect70:  b   hw_vect70       #INTC HW vector 70	
           .align ALIGN_OFFSET 
hw_vect71:  b   hw_vect71       #INTC HW vector 71	
           .align ALIGN_OFFSET 
hw_vect72:  b   hw_vect72       #INTC HW vector 72	
           .align ALIGN_OFFSET 
hw_vect73:  b   hw_vect73       #INTC HW vector 73	
           .align ALIGN_OFFSET 
hw_vect74:  b   hw_vect74       #INTC HW vector 74	
           .align ALIGN_OFFSET 
hw_vect75:  b   hw_vect75       #INTC HW vector 75	
           .align ALIGN_OFFSET 
hw_vect76:  b   hw_vect76       #INTC HW vector 76	
           .align ALIGN_OFFSET 
hw_vect77:  b   hw_vect77       #INTC HW vector 77	
           .align ALIGN_OFFSET 
hw_vect78:  b   hw_vect78       #INTC HW vector 78	
           .align ALIGN_OFFSET 
hw_vect79:  b   hw_vect79       #INTC HW vector 79	
           .align ALIGN_OFFSET 
hw_vect80:  b   hw_vect80       #INTC HW vector 80	
           .align ALIGN_OFFSET 
hw_vect81:  b   hw_vect81       #INTC HW vector 81	
           .align ALIGN_OFFSET 
hw_vect82:  b   hw_vect82       #INTC HW vector 82	
           .align ALIGN_OFFSET 
hw_vect83:  b   hw_vect83       #INTC HW vector 83	
           .align ALIGN_OFFSET 
hw_vect84:  b   hw_vect84       #INTC HW vector 84	
           .align ALIGN_OFFSET 
hw_vect85:  b   hw_vect85       #INTC HW vector 85	
           .align ALIGN_OFFSET 
hw_vect86:  b   hw_vect86       #INTC HW vector 86	
           .align ALIGN_OFFSET 
hw_vect87:  b   hw_vect87       #INTC HW vector 87	
           .align ALIGN_OFFSET 
hw_vect88:  b   hw_vect88       #INTC HW vector 88	
           .align ALIGN_OFFSET 
hw_vect89:  b   hw_vect89       #INTC HW vector 89	
           .align ALIGN_OFFSET 
hw_vect90:  b   hw_vect90       #INTC HW vector 90	
           .align ALIGN_OFFSET 
hw_vect91:  b   hw_vect91       #INTC HW vector 91	
           .align ALIGN_OFFSET 
hw_vect92:  b   hw_vect92       #INTC HW vector 92	
           .align ALIGN_OFFSET 
hw_vect93:  b   hw_vect93       #INTC HW vector 93	
           .align ALIGN_OFFSET 
hw_vect94:  b   hw_vect94       #INTC HW vector 94	
           .align ALIGN_OFFSET 
hw_vect95:  b   hw_vect95       #INTC HW vector 95	
           .align ALIGN_OFFSET 
hw_vect96:  b   hw_vect96       #INTC HW vector 96	
           .align ALIGN_OFFSET 
hw_vect97:  b   hw_vect97       #INTC HW vector 97	
           .align ALIGN_OFFSET 
hw_vect98:  b   hw_vect98       #INTC HW vector 98	
           .align ALIGN_OFFSET 
hw_vect99:  b   hw_vect99       #INTC HW vector 99	
           .align ALIGN_OFFSET 
hw_vect100:  b   hw_vect100       #INTC HW vector 100	
           .align ALIGN_OFFSET 
hw_vect101:  b   hw_vect101       #INTC HW vector 101	
           .align ALIGN_OFFSET 
hw_vect102:  b   hw_vect102       #INTC HW vector 102	
           .align ALIGN_OFFSET 
hw_vect103:  b   hw_vect103       #INTC HW vector 99	
           .align ALIGN_OFFSET 
hw_vect104:  b   hw_vect104       #INTC HW vector 104	
           .align ALIGN_OFFSET 
hw_vect105:  b   hw_vect105       #INTC HW vector 105	
           .align ALIGN_OFFSET 
hw_vect106:  b   hw_vect106       #INTC HW vector 106	
           .align ALIGN_OFFSET 
hw_vect107:  b   hw_vect107       #INTC HW vector 107	
           .align ALIGN_OFFSET 
hw_vect108:  b   hw_vect108       #INTC HW vector 108	
           .align ALIGN_OFFSET 
hw_vect109:  b   hw_vect109       #INTC HW vector 109	
           .align ALIGN_OFFSET 
hw_vect110:  b   hw_vect110       #INTC HW vector 110	
           .align ALIGN_OFFSET 
hw_vect111:  b   hw_vect111       #INTC HW vector 111	
           .align ALIGN_OFFSET 
hw_vect112:  b   hw_vect112       #INTC HW vector 112	
           .align ALIGN_OFFSET 
hw_vect113:  b   hw_vect113       #INTC HW vector 113	
           .align ALIGN_OFFSET 
hw_vect114:  b   hw_vect114       #INTC HW vector 114	
           .align ALIGN_OFFSET 
hw_vect115:  b   hw_vect115       #INTC HW vector 115	
           .align ALIGN_OFFSET 
hw_vect116:  b   hw_vect116       #INTC HW vector 116	
           .align ALIGN_OFFSET 
hw_vect117:  b   hw_vect117       #INTC HW vector 117	
           .align ALIGN_OFFSET 
hw_vect118:  b   hw_vect118       #INTC HW vector 118	
           .align ALIGN_OFFSET 
hw_vect119:  b   hw_vect119       #INTC HW vector 119	
           .align ALIGN_OFFSET 
hw_vect120:  b   hw_vect120       #INTC HW vector 120	
           .align ALIGN_OFFSET 
hw_vect121:  b   hw_vect121       #INTC HW vector 121	
           .align ALIGN_OFFSET 
hw_vect122:  b   hw_vect122       #INTC HW vector 122	
           .align ALIGN_OFFSET 
hw_vect123:  b   hw_vect123       #INTC HW vector 123	
           .align ALIGN_OFFSET 
hw_vect124:  b   hw_vect124       #INTC HW vector 124	
           .align ALIGN_OFFSET 
hw_vect125:  b   hw_vect125       #INTC HW vector 125	
           .align ALIGN_OFFSET 
hw_vect126:  b   hw_vect126       #INTC HW vector 126	
           .align ALIGN_OFFSET 
hw_vect127:  b   hw_vect127       #INTC HW vector 127	
           .align ALIGN_OFFSET 
hw_vect128:  b   hw_vect128       #INTC HW vector 128	
           .align ALIGN_OFFSET 
hw_vect129:  b   hw_vect129       #INTC HW vector 129	
           .align ALIGN_OFFSET 
hw_vect130:  b   hw_vect130       #INTC HW vector 130	
           .align ALIGN_OFFSET 
hw_vect131:  b   hw_vect131       #INTC HW vector 131	
           .align ALIGN_OFFSET 
hw_vect132:  b   hw_vect132       #INTC HW vector 132	
           .align ALIGN_OFFSET 
hw_vect133:  b   hw_vect133       #INTC HW vector 133	
           .align ALIGN_OFFSET 
hw_vect134:  b   hw_vect134       #INTC HW vector 134	
           .align ALIGN_OFFSET 
hw_vect135:  b   hw_vect135       #INTC HW vector 135	
           .align ALIGN_OFFSET 
hw_vect136:  b   hw_vect136       #INTC HW vector 136	
           .align ALIGN_OFFSET 
hw_vect137:  b   hw_vect137       #INTC HW vector 137	
           .align ALIGN_OFFSET 
hw_vect138:  b   hw_vect138       #INTC HW vector 138	
           .align ALIGN_OFFSET 
hw_vect139:  b   hw_vect139       #INTC HW vector 139	
           .align ALIGN_OFFSET 
hw_vect140:  b   hw_vect140       #INTC HW vector 140	
           .align ALIGN_OFFSET 
hw_vect141:  b   hw_vect141       #INTC HW vector 141	
           .align ALIGN_OFFSET 
hw_vect142:  b   hw_vect142       #INTC HW vector 142	
           .align ALIGN_OFFSET 
hw_vect143:  b   hw_vect143       #INTC HW vector 143	
           .align ALIGN_OFFSET 
hw_vect144:  b   hw_vect144       #INTC HW vector 144	
           .align ALIGN_OFFSET 
hw_vect145:  b   hw_vect145       #INTC HW vector 145	
           .align ALIGN_OFFSET 
hw_vect146:  b   esci0_handler       #INTC HW vector 146
           .align ALIGN_OFFSET 
hw_vect147:  b   hw_vect147       #INTC HW vector 147	
           .align ALIGN_OFFSET 
hw_vect148:  b   hw_vect148       #INTC HW vector 148	
           .align ALIGN_OFFSET 
hw_vect149:  b   esci1_handler       #INTC HW vector 149	
           .align ALIGN_OFFSET 
hw_vect150:  b   hw_vect150       #INTC HW vector 150	

