local mapa = {
  ambient="0.1,0.1,0.1",
  gravity="0 -9.8 0",
  entities={
    { 
      name="Sinbad",
      id=1,
      components={
        transform={
          position="0,0,0",
          rotation="0,0,60",
          scale="1,1,1",
          parent="-1"
        },
        renderer={
          mesh="Sinbad.mesh",
          material="",
          visible="true"
        },
        rigidbody={
          shape="0",
          mass="54",
          inertia="0,0,0",
          restitution="0.2",
          damping="0.2,0.2",
          trigger="false",
          kinematic ="false"
        }
      }
    },
    {
      name="Camera",
      id=2,
      components={
        transform={
          position="0,0,200",
          rotation="0,0,0",
          scale="1,1,1",
          parent="1"
        },
        camera={
          near="0.1",
          far="1000",
          autoaspect="true",
          aspect="1.78",
          fov="50",
          proyection="1",
          viewport="0,0,1,1",
          color="1.0,0.5,0.3137"
        }
        ,
        skybox={
          enable="true",
          planenormal="Z",
          planepos="20",
          materialname="sky/space",
          scale="1",
          tiling="1",
          drawfirst="true",
          bow="10.0",
          xsegments="10",
          ysegments="10"
        }
      }
    },
    -- {
    -- name="Luz",
    -- id=3,
    -- components={
    --   transform={
    --     position="50,0,0",
    --     rotation="0,0,0",
    --     scale="1,1,1",
    --     parent="-1"
    --   },
    --   light={
    --     type="0",
    --     attenuation="",
    --     shadows="true",
    --     diffuse="1,0.2,1,1",
    --     specular="1,1,1,1",
    --     spotinner="",
    --     spotouter=""
    --     }
    --   }
    -- },
    {
      name="Suelo",
      id=4,
      components={
        transform={
          position="0,-200,0",
          rotation="0,0,0",
          scale="0.2,0.2,0.2",
          parent="-1"
        },
        renderer={
          mesh="cube.mesh",
          material="",
          visible="true"
        },
        rigidbody={
          shape="0",
          mass="0",
          inertia="0,0,0",
          restitution="0.2",
          damping="0.2,0.2",
          trigger="false",
          kinematic ="false"
        }
      }
    },
    {
    	name="Boton",
    	id=5,
    	components={
        button={
          text="",
          position="0.5,0.5",
          size="100,100",
          name="botonSalir",
          properties="NormalImage,TaharezLook/ButtonSalir,HoverImage,TaharezLook/ButtonSalirHover,PushedImage,TaharezLook/ButtonSalirPushed",
          type="EXIT",
          showCursor="true",
          continueBullet="false",
          nextScene=""
        }   	
    	},
    }
  }
}

function GetMapa ()
  return mapa
end