#include "colors.inc"
#include "shapes.inc"
#include "textures.inc"

/*
camera {
  location <0,15,0>
  look_at <0,3,0>
}
 
background { LightSteelBlue }

light_source { <500,500,-1000> color White}


plane {
  y, 0   
  pigment { checker Green White }
}
  */


#declare computerblack_plastic = 
texture {
    //T_Silver_1A 
    pigment{Black}
    normal{ 
        bumps 0.05 scale 1 
    }
    finish{
      ambient 0
      diffuse .8
      reflection .03
      specular 1
      roughness .1
    }
}
/*
#declare computerblack_plastic = texture {
	pigment {color rgb <0.2,0.2,0.2>} 
	normal { bumps 0.2 scale 0.5 }
	finish { phong 0.1 }
}
*/
#declare Mouse =
union {
    intersection{//Mouse Body
        sphere {<0,0,0>, 5}
        box{<-2.5,0,-5>, <2.5,5,5> translate <0,3,0>}
    }
    union{//Mouse Buttons
        intersection{//Left Button
            sphere {<0,0,0>, 5}
            box{<-2.5,0,-5>, <2.5,5,5> translate <0,3,0>}
            box{<0,0,-5>, <2.,2,1> translate <0,3.3,-1.8>}
            translate <.3,2.0>
        }
        intersection{//Right Button
            sphere {<0,0,0>, 5}
            box{<-2.5,0,-5>, <2.5,5,5> translate <0,3,0>}
            box{<0,0,-5>, <2.0,2,1> translate <0,3.3,-1.8>}
            scale <-1,0,0>
            translate <-.3,2.0>
        }
        rotate 2*x
        translate <0,-2.1,-.30>
    }
    union{//Scroll
        sphere{
            <0,5,0>, .7
            scale <.3,0,0>
        } 
        translate <0,-1,-2.5>
        pigment{Red}
    }
    
    texture{computerblack_plastic}
}

//chamada
//object {Mouse}   