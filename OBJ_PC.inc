#include "colors.inc"
#include "EXT_pc_case.inc"
#include "EXT_keyboard.inc"
#include "EXT_mouse.inc"
/*
camera {
  location <0,1,-10> 
 // location <0,10,0>
  look_at <0,0,0>
}

 
background { LightSteelBlue }

light_source { <500,500,-1000> color White}  
light_source { <500,500,-1000> color White}


plane {
  y, 0   
  pigment { checker Green White }
}
 */
 
#declare Monitor =
union{
 //base
 cylinder { 
   <0, 0, 0> <0, 0.1, 0>, 1 
 }
 
//pé
 cylinder { 
   <0, 0, 0.2> <0, 1.5, 0.1>, 0.2 
 }
 
 //tela 
 box {
  <-2, 0.7, -0.2> <2, 2.7, 0.1> 
 }
 box {
  <-1.8, 0.9, -0.21> <1.8, 2.5, -0.1>  
  texture {
    pigment {
      image_map {tga "EXT_SCREEN.TGA"} 
      //rotate <0,90,0>
      scale <5,5,3>
      translate <-1.6,0,0>
    }
  } 
 }

  pigment {color rgb <0.3,0.3,0.3>} 
}

/*#declare Gabinete =
union{
  box {
    <-0.5, 0, -1.5> <0.5, 3, 1.5>
  }

  pigment{ color White }
}  */

/*#declare Teclado =
union{
  box {
  <-1.2, 0, 0> <1.2, 0.1, 1.5>
 }

  pigment{ color White }
}  */
 /*
#declare Mouse =
union{
  box {
    <-0.15, 0, 0> <0.15, 0.2, 0.8>
  }

  pigment{ color White }
}
     */
#declare PC = union {
  object{Monitor}
  /*object{
    SYNCMASTER17 scale <.006,.006,.006>
    rotate<0,-90,0>
    translate<-0.2,0,0>
  }*/
  /*object{
    Gabinete
    translate<-3,0,-0.5>
  } */
  object{
    QUICK_BIGTOWER 
    scale <.006,.006,.006>
    rotate<0,-90,0>
    translate<-3,0,-2>
  }
  /*object{
    Teclado
    translate<0,0,-2.8>
    }  */
  object {
    KEYBOARD 
    scale <.0065,.0065,.0065> 
    rotate<0,-90,0>
    translate<0,0,-1.9>
  }
  object{
    Mouse
    scale <.1,.1,.1>   
    rotate<0,180,0>
    translate<2,-0.25,-2>
  }
  translate<0.8,0,0.8>

}

//chamada
//object {PC}   