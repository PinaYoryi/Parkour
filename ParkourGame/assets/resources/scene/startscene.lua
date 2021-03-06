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
          rotation="0,0,0",
          scale="1,1,1",
          parent="-1"
        },
        rigidbody={
          shape="-1",
          mass="10",
          inertia="0,0,0",
          restitution="0.2",
          damping="0.2,0.2",
          trigger="false",
          kinematic="false"
        },
        camera={
          near="0.1",
          far="1000",
          autoaspect="true",
          aspect="1.78",
          fov="50",
          proyection="1",
          viewport="0,0,1,1",
          color="0,0,0"
        },
        renderer={
          mesh="Sinbad.mesh",
          material="",
          visible="false"
        },
        playercontroller={
          speed="175",
          maxJump="2",
          jumpStr="7200"
        }
      }
    },
    --{ 
    --  name="Drone",
    --  id=5,
    --  components={
    --    transform={
    --      position="0,40,0",
    --      rotation="0,90,0",
    --      scale="1,1,1"
    --    },
    --    renderer={
    --      mesh="Sinbad.mesh",
    --      material="",
    --      visible="true"
    --    },
    --    rigidbody={
    --      shape="0",
    --      mass="54",
    --      inertia="0,0,0",
    --      restitution="0.2",
    --      damping="0.2,0.2",
    --      trigger="false",
    --      kinematic="true"
    --    },
    --    shotai={
    --      objective="1",
    --      proyectile="bala.prefab",
    --      rof="3"
    --    }
    --  }
    --},
    {
    name="Luz",
    id=3,
    components={
      transform={
        position="50,0,0",
        rotation="290,145,0",
        scale="1,1,1",
        parent="-1"
      },
      light={
        type="1",
        attenuation="",
        shadows="true",
        diffuse="0.7,0.7,0,1",
        specular="1,1,1,1",
        spotinner="",
        spotouter=""
        }
      }
    },
    {
      name="Suelo",
      id=4,
      components={
        transform={
          position="0,-100,0",
          rotation="0,0,0",
          scale="0.75,0.1,0.75",
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
          kinematic="false"
        },
        floor={

        }
      }
    },
    {
      name="Plat1",
      id=5,
      components={
        transform={
          position="50,-98,-100",
          rotation="0,0,0",
          scale="0.7,0.1,0.7",
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
          kinematic="false"
        },
        floor={
          
        }
      }
    },
    {
      name="Plat2",
      id=6,
      components={
        transform={
          position="10,-97,-200",
          rotation="90,0,0",
          scale="0.7,0.1,0.7",
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
          kinematic="false",
          parent="-1"
        },
        floor={
          
        }
      }
    }      
  }
}

function GetMapa ()
  return mapa
end

