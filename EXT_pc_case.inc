// ***************************************************************************
// Objects provided by this file are:
//	FLOPPYDRIVE
//	MODRIVE
//	CDROMDRIVE
//	CDRECDRIVE
//	baycover1
//	baycover2
//	pcscrewhead
//	BIGTOWER
//	QUICK_BIGTOWER
//
// Textures provided by this file are:
//	computerwhite_plastic
//	brightgreen_LED
//	dark_LED
// ***************************************************************************
// Scale: 1 millimeter per POV unit.
// ***************************************************************************
// *               Manfred.Agne@munich.netsurf.de  (1998)                    *
// *                     Feel free to use this file.                         *
// ***************************************************************************


/*
#include "colors.inc"
camera {
  location <-20,1,0>
  look_at <0,5,0>
}
 
background { LightSteelBlue }

light_source { <500,500,-1000> color White}


plane {
  y, 0   
  pigment { checker Green Black }
} 
*/

#include "EXT_plugs.inc"

#declare computerwhite_plastic = texture {
  //pigment {color rgb <0.9647,0.9098,0.7529>}
  pigment {color rgb <0.3,0.3,0.3>} 
  //normal  { bumps 0.5 scale 0.1 }
  finish  { phong 0.1 }
}
#declare brightgreen_LED = texture{
  pigment {color rgb<0,1,0>} 
  finish  {ambient 0.8}
}
#declare dark_LED = texture {
  pigment { color rgbf<0.5, 0.6, 0.5, 1.0> }
  finish {
    ambient 0
    diffuse 0.1
    reflection 0.1
    refraction 1
    ior 1.5
    phong 0.1
    phong_size 20
  }
}
//############################################################################
// The front panel of a standard 3.5" floppy drive. Lower left corner is 
// <0,0,0>, top right corner is <0,26,-101>, depth is 5mm. If you want to
// model a complete drive, simply add the body to the front panel.
// The quartic is the eject button. If you don't like it, or if it doesn't
// render well you can replace it by the box just below it.
//----------------------------------------------------------------------------
#declare FLOPPYDRIVE =
union {
  difference {
    box{< 0, 0,  0>,<  5,26,-101>}
    box{<-1,14, -5>,<  6,19, -96>}
    box{<-1,13,-25>,<  6,19, -76>}
    box{< 0, 0,-33>,<-20,10, -68> rotate<0,0,70> translate<5,18,0>}
    box{<-1, 4,-72>,<  5,10, -84>}
    box{<-1, 4,-19>,<  5, 6, -25>}
  }
  box{<3.5,0, 0>,<  5,26,-101>}
  quartic {
  < 1.0,  0.0,  0.0,   0.0,    0.0,  0.0,  0.0,  0.0,  0.0,   0.0,
    0.0,  0.0,  0.0,   0.0,    0.0,  0.0,  0.0,  0.0,  0.0,   0.0,
    1.0,  0.0,  0.0,   0.0,    0.0,  0.0,  0.0,  0.0,  0.0,   0.0,
    1.0,  0.0,  0.0,   0.0, -1000.0 >
  scale<0.6,0.5,1> translate<0,7,-78>
  }
  //box{<-2,4.5,-72.5>,<  5,9.5, -83.5>}
  box{<0.2, 4,-19>,<  5, 6, -25> texture {brightgreen_LED}}
  texture{computerwhite_plastic}
}
//############################################################################
// The front panel of a 128 MB, 3.5" floppy drive. Lower left corner is 
// <0,0,0>, top right corner is <0,26,-101>, depth is 5mm. 
// I use MO disks as primary backup medium. If the SCSI bus is ok, nothing
// beats the reliability ob MO disks, IMHO.
//----------------------------------------------------------------------------
#declare MODRIVE =
union {
  difference {
    box{< 0, 0,  0>,<5,26,-101>}
    box{<-1,14, -5>,<6,22, -96>}
    box{<-1,13,-16>,<6,22, -85>}
    box{<-1, 4,-78>,<3, 8, -91>}
    box{< 0, 0,-16>,<-20,20, -85> rotate<0,0,45> translate<6,18,0>}
    box{<-2, 0, -5>,<-20,20, -96> rotate<0,0,45> translate<6,17.5,0>}
    cylinder{<-1,10,-84>,<6,10,-84>,0.7}
  }
  box{<  2,13, -5>,<5,22,-96>}
  box{<1.5,14, -6>,<2,21,-11>}
  box{<1.5,14,-91>,<2,21,-96>}
  box{<-1,4.5,-78.5>,<3,7.5,-90.5>}
  box{<-0.1,5,-13>,<2,7,-18> texture{brightgreen_LED}}
  texture{computerwhite_plastic}
}
//############################################################################
// The front panel of my CD-ROM drive (5.25", of course). Lower left corner is 
// <0,0,0>, top right corner is <0,42,-149>, depth is 5mm. If you want to
// model a complete drive, simply add the body to the front panel. I didn't
// do it since the necessary level of detail depends on what you want to do
// with it. For example, if you need the model to illustrate a manual, you'll
// probably need the rear connector, jumpers and screw holes which are 
// superfluous for a model of a complete (closed) PC case.
//----------------------------------------------------------------------------
#declare CDROMDRIVE =
union {
  difference {
    box{<0,0,0>,<5,42,-149>}
    box{<-1,7,-31>,<6,11,-43>}
    cylinder{<-1,10,-115>,<2,10,-115>,4}
    cylinder{<-1,10,-134>,<2,10,-134>,4}
    cylinder{<-1,10, -19>,<6,10, -19>,4}
    cylinder{<-1,10, -57>,<2,10, -57>,2}
    union{
      box{<-1,21,-8>,<2,36,-141>}
      intersection{
        cylinder{<-1,519,-74.5>,<2,519,-74.5>,501}
        plane{<0,1,0>,21}
      }
    }
  }
  cylinder{<9,7.5,-37>,<9,10.5,-37>,10}
  difference{
    box{<0,22, -9>,<  1,35,-140>}
    cylinder{<-1,24,-47>,<2,24,-47>,0.7}
  }
  intersection{
    cylinder{<0,519,-74.5>,<1,519,-74.5>,500}
    plane{<0,1,0>,22}
  }
  intersection{
    sphere{<6,10,-115>,7}
    cylinder{<-2,10,-115>,<1,10,-115>,3.5}
  }
  intersection{
    sphere{<6,10,-134>,7}
    cylinder{<-2,10,-134>,<1,10,-134>,3.5}
  }
  difference{
    cylinder{<-1,10, -19>,<6,10, -19>,4}
    cylinder{<-2,10, -19>,<7,10, -19>,2}
    //texture{T_Chrome_2A}
  }
  cylinder{<0.1,10, -57>,<2,10, -57>,2 texture{brightgreen_LED}}
  texture{computerwhite_plastic}
}
//############################################################################
// The front panel of my CD-Recorder (5.25", of course). Lower left corner is 
// <0,0,0>, top right corner is <0,42,-149>, depth is 5mm. If you want to
// model a complete drive, simply add the body to the front panel.
//----------------------------------------------------------------------------
#declare CDRECDRIVE =
union {
  difference {
    box{<0,0,0>,<5,42,-149>}
    box{<-1, 7, -31>,<6,11, -43>}
    box{<-1,21,  -8>,<2,36,-141>}
    box{<-1, 7,-114>,<2,11,-126>}
    cylinder{<-1,10, -19>,<6,10, -19>,4}
    cylinder{<-1,16, -98>,<6,16, -98>,0.7}
  }
  box{<-1, 7.5,-114.5>,<2,10.5,-125.5>}
  box{<1.0,22,  -9>,<5,35,-140>}
  box{<0.8,23, -10>,<1,34, -20>}
  box{<0.8,23,-129>,<1,34,-139>}
  cylinder{<9,7.5,-37>,<9,10.5,-37>,10}
  difference{
    cylinder{<-1,10, -19>,<6,10, -19>,4}
    cylinder{<-2,10, -19>,<7,10, -19>,2}
    //texture{T_Chrome_2A}
  }
  box{<-0.1,8,-95>,<2,10,-100> texture{brightgreen_LED}}
  texture{computerwhite_plastic}
}
//############################################################################
// Front panel for empty 3.5" drive bay.
//----------------------------------------------------------------------------
#declare baycover1 =
union{
  box{<0.5,0,0>,<5,26,-101>}
  box{<0,  1,1>,<5,25,-100>}
  texture{computerwhite_plastic}
}
//############################################################################
// Front panel for empty 5.25" drive bay.
//----------------------------------------------------------------------------
#declare baycover2 =
union{
  box{<0.5,0,0>,<5,42,-149>}
  box{<0,  1,1>,<5,41,-148>}
  texture{computerwhite_plastic}
}
//############################################################################
// On of the screws typically used in a PC. This is only the screw head!
//----------------------------------------------------------------------------
#declare pcscrewhead =
union{
  cylinder{<0,0,0>,<0,0.6,0>,4}
  difference {
    intersection {
      plane {<0,-1,0>, 0  }
      plane {<0, 1,0>,3.5 }
      plane {<1, 0,0>,3.0 }   
      plane {<1, 0,0>,3.0 rotate <0, 60,0>}   
      plane {<1, 0,0>,3.0 rotate <0,120,0>}   
      plane {<1, 0,0>,3.0 rotate <0,180,0>}   
      plane {<1, 0,0>,3.0 rotate <0,240,0>}   
      plane {<1, 0,0>,3.0 rotate <0,300,0>}   
      sphere{<0, 0,0>,3.45 scale  <1,2,1>}
    }
    cylinder{<0,3,0>,<0,4,0>,2.7}
    box{<-0.4,-2,-2>,<0.4,2,2> rotate<45,0,0> translate<0,3.7,0>}
    box{<-0.4,-2,-2>,<0.4,2,2> rotate<45,0,0> translate<0,3.7,0> rotate<0,90,0>}
  }
  //texture{T_Silver_3A}
}
//############################################################################
// This is a model of my PC. It has a Floppy drive, a 128 MB Magneto Optical
// Drive, a CD Drive, and a CD Recorder. You can add more drives by replacing
// the "object{baycover2 ...}" statements in the sourcecode (for 5.25" drives)
// or the "object{baycover1 ...}" statements for 3.5" drives. Note however, 
// that in the real thing, one or two of the apparently empty 3.5" slots are
// occupied by harddisks!
// Since this model does also include the rear connectors and several air 
// in- and outlets it renders relatively slowly. You find a less detailed 
// version below.
//----------------------------------------------------------------------------
#declare BIGTOWER =
union {
  box{<30,0,110>,<20,20,-110>}
  difference {
    box{<30,20,110>,<7,175,-110>}
    cylinder{<0,160, 100>,<30,160, 100>,1}
    cylinder{<0,160,  80>,<30,160,  80>,1}
    cylinder{<0,160,  60>,<30,160,  60>,1}
    cylinder{<0,160,  40>,<30,160,  40>,1}
    cylinder{<0,160,  20>,<30,160,  20>,1}
    cylinder{<0,160,   0>,<30,160,   0>,1}
    cylinder{<0,160, -20>,<30,160, -20>,1}
    cylinder{<0,160, -40>,<30,160, -40>,1}
    cylinder{<0,160, -60>,<30,160, -60>,1}
    cylinder{<0,160, -80>,<30,160, -80>,1}
    cylinder{<0,160,-100>,<30,160,-100>,1}

    cylinder{<0,140, 100>,<30,140, 100>,1}
    cylinder{<0,140,  80>,<30,140,  80>,1}
    cylinder{<0,140,  60>,<30,140,  60>,1}
    cylinder{<0,140,  40>,<30,140,  40>,1}
    cylinder{<0,140,  20>,<30,140,  20>,1}
    cylinder{<0,140,   0>,<30,140,   0>,1}
    cylinder{<0,140, -20>,<30,140, -20>,1}
    cylinder{<0,140, -40>,<30,140, -40>,1}
    cylinder{<0,140, -60>,<30,140, -60>,1}
    cylinder{<0,140, -80>,<30,140, -80>,1}
    cylinder{<0,140,-100>,<30,140,-100>,1}

    cylinder{<0,120, 100>,<30,120, 100>,1}
    cylinder{<0,120,  80>,<30,120,  80>,1}
    cylinder{<0,120,  60>,<30,120,  60>,1}
    cylinder{<0,120,  40>,<30,120,  40>,1}
    cylinder{<0,120,  20>,<30,120,  20>,1}
    cylinder{<0,120,   0>,<30,120,   0>,1}
    cylinder{<0,120, -20>,<30,120, -20>,1}
    cylinder{<0,120, -40>,<30,120, -40>,1}
    cylinder{<0,120, -60>,<30,120, -60>,1}
    cylinder{<0,120, -80>,<30,120, -80>,1}
    cylinder{<0,120,-100>,<30,120,-100>,1}

    cylinder{<0,100, 100>,<30,100, 100>,1}
    cylinder{<0,100,  80>,<30,100,  80>,1}
    cylinder{<0,100,  60>,<30,100,  60>,1}
    cylinder{<0,100,  40>,<30,100,  40>,1}
    cylinder{<0,100,  20>,<30,100,  20>,1}
    cylinder{<0,100,   0>,<30,100,   0>,1}
    cylinder{<0,100, -20>,<30,100, -20>,1}
    cylinder{<0,100, -40>,<30,100, -40>,1}
    cylinder{<0,100, -60>,<30,100, -60>,1}
    cylinder{<0,100, -80>,<30,100, -80>,1}
    cylinder{<0,100,-100>,<30,100,-100>,1}

    cylinder{<0, 80, 100>,<30, 80, 100>,1}
    cylinder{<0, 80,  80>,<30, 80,  80>,1}
    cylinder{<0, 80,  60>,<30, 80,  60>,1}
    cylinder{<0, 80,  40>,<30, 80,  40>,1}
    cylinder{<0, 80,  20>,<30, 80,  20>,1}
    cylinder{<0, 80,   0>,<30, 80,   0>,1}
    cylinder{<0, 80, -20>,<30, 80, -20>,1}
    cylinder{<0, 80, -40>,<30, 80, -40>,1}
    cylinder{<0, 80, -60>,<30, 80, -60>,1}
    cylinder{<0, 80, -80>,<30, 80, -80>,1}
    cylinder{<0, 80,-100>,<30, 80,-100>,1}

    cylinder{<0, 60, 100>,<30, 60, 100>,1}
    cylinder{<0, 60,  80>,<30, 60,  80>,1}
    cylinder{<0, 60,  60>,<30, 60,  60>,1}
    cylinder{<0, 60,  40>,<30, 60,  40>,1}
    cylinder{<0, 60,  20>,<30, 60,  20>,1}
    cylinder{<0, 60,   0>,<30, 60,   0>,1}
    cylinder{<0, 60, -20>,<30, 60, -20>,1}
    cylinder{<0, 60, -40>,<30, 60, -40>,1}
    cylinder{<0, 60, -60>,<30, 60, -60>,1}
    cylinder{<0, 60, -80>,<30, 60, -80>,1}
    cylinder{<0, 60,-100>,<30, 60,-100>,1}

    cylinder{<0, 40, 100>,<30, 40, 100>,1}
    cylinder{<0, 40,  80>,<30, 40,  80>,1}
    cylinder{<0, 40,  60>,<30, 40,  60>,1}
    cylinder{<0, 40,  40>,<30, 40,  40>,1}
    cylinder{<0, 40,  20>,<30, 40,  20>,1}
    cylinder{<0, 40,   0>,<30, 40,   0>,1}
    cylinder{<0, 40, -20>,<30, 40, -20>,1}
    cylinder{<0, 40, -40>,<30, 40, -40>,1}
    cylinder{<0, 40, -60>,<30, 40, -60>,1}
    cylinder{<0, 40, -80>,<30, 40, -80>,1}
    cylinder{<0, 40,-100>,<30, 40,-100>,1}
  }
  difference {
    box{< 0,175,110>,<30,550,-110>}
    box{<-1,200, 99>,<31,523,  -3>}
    box{<-1,281, 99>,<31,496, -51>}
    cylinder{<-1,523,-80>,<5,523,-80>, 2}
    cylinder{<-1,498,-80>,<5,498,-80>, 2}
    cylinder{<-1,465,-80>,<5,465,-80>,10}
  }
  object{MODRIVE      translate<0,496.5,98.5>}
  object{baycover2    translate<0,453.5,98.5>}
  object{baycover2    translate<0,410.5,98.5>}
  object{baycover2    translate<0,367.5,98.5>}
  object{CDRECDRIVE   translate<0,324.5,98.5>}
  object{CDROMDRIVE   translate<0,281.5,98.5>}
  object{FLOPPYDRIVE  translate<0,254.5,98.5>}
  object{baycover1    translate<0,227.5,98.5>}
  object{baycover1    translate<0,200.5,98.5>}
  cylinder{<0,523,-80>,<5,523,-80>, 2 texture{dark_LED}}
  cylinder{<0,498,-80>,<5,498,-80>, 2 texture{brightgreen_LED}}
  intersection{
    sphere{<18,465,-80>,20}
    cylinder{<-1,465,-80>,<5,465,-80>,9.5}
  }
  box{<  30,  0,109.5>,<30.5,549.5,-109.5>}
  box{<30.5,  0,  110>,< 400,550  ,-110  >}
  box{< 400,  0,  110>,< 431,550  ,  95  >}
  box{< 400,  0, -110>,< 431,550  , -95  >}
  box{< 400,535,  110>,< 431,550  ,-110  >}
  difference{
    box{<400,  0,  105>,< 430,545,-105>}
    box{<415, 20,   20>,< 431,172, -90>}
    box{<415,171.99,-30>,< 431,334, -90>}
    #declare yy=0;
    #while (yy<=6)
      box{<413,(25+21*yy),21>,<420,(39+21*yy),-85>}
      #declare yy=(yy+1);
    #end
    union{
      box{<429,200,85>,<431,335,15>}
      cylinder{<429,240,50>,<431,240,50>,40}
      #declare yy=-5;
      #while (yy<=5)
        cylinder{<431,(240+(7*yy)),18>,<400,(240+(7*yy)),18>,2} 
        cylinder{<431,(240+(7*yy)),32>,<400,(240+(7*yy)),32>,2} 
        cylinder{<431,(240+(7*yy)),43>,<400,(240+(7*yy)),43>,2} 
        cylinder{<431,(240+(7*yy)),57>,<400,(240+(7*yy)),57>,2} 
        cylinder{<431,(240+(7*yy)),68>,<400,(240+(7*yy)),68>,2} 
        cylinder{<431,(240+(7*yy)),82>,<400,(240+(7*yy)),82>,2} 
        box{     <431,(242+(7*yy)),43>,<400,(238+(7*yy)),57>}
        box{     <431,(242+(7*yy)),18>,<400,(238+(7*yy)),32>}
        box{     <431,(242+(7*yy)),68>,<400,(238+(7*yy)),82>}
        #declare yy=(yy+1);
      #end 
    }
    texture{
      pigment{rgb<0.6,0.6,0.6>}
      finish {brilliance 0.5 diffuse 0.6 metallic specular 0.10 roughness 0.5 reflection 0.2}
    }
  }
  object{pcscrewhead rotate<0,0,-90> translate<431,510,-102.5>}
  object{pcscrewhead rotate<0,0,-90> translate<431,280,-102.5>}
  object{pcscrewhead rotate<0,0,-90> translate<431, 50,-102.5>}
  object{pcscrewhead rotate<0,0,-90> translate<431,510, 102.5>}
  object{pcscrewhead rotate<0,0,-90> translate<431,280, 102.5>}
  object{pcscrewhead rotate<0,0,-90> translate<431, 50, 102.5>}

  object{pcscrewhead rotate<0,0,-90> translate<430,192,   5.0>}
  object{pcscrewhead rotate<0,0,-90> translate<430,205, -21.0>}
  object{pcscrewhead rotate<0,0,-90> translate<430,330,   5.0>}
  object{pcscrewhead rotate<0,0,-90> translate<430,295, -21.0>}

  object{pcscrewhead rotate<0,0,-90> translate<430,305,  90.0>}
  object{pcscrewhead rotate<0,0,-90> translate<430,192,  80.0>}
  object{SUB_D25_FEMALE rotate<0,180,0> rotate<0,0,-90> translate<430,138, 65>}
  object{SUB_D25_FEMALE rotate<0,180,0> rotate<0,0,-90> translate<413, 53,-22>}
  object{SUB_D15_FEMALE rotate<0,180,0> rotate<0,0,-90> translate<413, 74,-68>}
  object{SUB_D15_FEMALE rotate<0,0,-90> translate<413,158,-13>}
  object{SUB_D9_MALE    rotate<0,0,-90> translate<413,158,-54>}
  object{SUB_D9_MALE    rotate<0,0,-90> rotate<-90,0,0> translate<413,190,-80>}
  object{SUB_D25_FEMALE rotate<0,0,-90> rotate<-90,0,0> translate<413,235,-80>}
  object{SUB_D9_MALE    rotate<0,0,-90> rotate<-90,0,0> translate<413,311,-80>}
  texture{computerwhite_plastic}
}
//############################################################################
// The "quick" version of the PC above. No rear connectors, less details.
// Renders much faster.
//----------------------------------------------------------------------------
#declare QUICK_BIGTOWER =
union {
  box{<30,0,110>,<20,20,-110>}
  box{<30,20,110>,<7,175,-110>}
  difference {
    box{< 0,175,110>,<30,550,-110>}
    box{<-1,200, 99>,<31,523,  -3>}
    box{<-1,281, 99>,<31,496, -51>}
    cylinder{<-1,523,-80>,<5,523,-80>, 2}
    cylinder{<-1,498,-80>,<5,498,-80>, 2}
    cylinder{<-1,465,-80>,<5,465,-80>,10}
  }
  object{MODRIVE      translate<0,496.5,98.5>}
  object{baycover2    translate<0,453.5,98.5>}
  object{baycover2    translate<0,410.5,98.5>}
  object{baycover2    translate<0,367.5,98.5>}
  object{CDRECDRIVE   translate<0,324.5,98.5>}
  object{CDROMDRIVE   translate<0,281.5,98.5>}
  object{FLOPPYDRIVE  translate<0,254.5,98.5>}
  object{baycover1    translate<0,227.5,98.5>}
  object{baycover1    translate<0,200.5,98.5>}
  cylinder{<0,523,-80>,<5,523,-80>, 2 texture{dark_LED}}
  cylinder{<0,498,-80>,<5,498,-80>, 2 texture{brightgreen_LED}}
  intersection{
    sphere{<18,465,-80>,20}
    cylinder{<-1,465,-80>,<5,465,-80>,9.5}
  }
  box{<  30,  0,109.5>,<30.5,549.5,-109.5>}
  box{<30.5,  0,  110>,< 400,550  ,-110  >}
  box{< 400,  0,  110>,< 431,550  ,  95  >}
  box{< 400,  0, -110>,< 431,550  , -95  >}
  box{< 400,535,  110>,< 431,550  ,-110  >}
  difference{
    box{<400,  0,  105>,< 430,545,-105>}
    box{<415, 20,   20>,< 431,172, -90>}
    box{<415,171.99,-30>,< 431,334, -90>}
    union{
      box{<429,200,85>,<431,335,15>}
      cylinder{<429,240,50>,<431,240,50>,40}
    }
    texture{
      pigment{rgb<0.6,0.6,0.6>}
      finish {brilliance 0.5 diffuse 0.6 metallic specular 0.10 roughness 0.5 reflection 0.2}
    }
  }
  texture{computerwhite_plastic}
}
//**************************************************************************
//*** EOF *** EOF *** EOF *** EOF *** EOF *** EOF *** EOF *** EOF *** EOF **
//**************************************************************************
                                                                                   
//chamada
//object{QUICK_BIGTOWER scale <.02,.02,.02> }