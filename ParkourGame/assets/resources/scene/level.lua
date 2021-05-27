local mapa = {
  ambient="0.1,0.1,0.1",
  gravity="0 -9.8 0",
  entities={
    {
      name="Player",
      id=1,
      components={
        transform={
          position="0,-90,0",
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
        renderer={
          mesh="Sinbad.mesh",
          material="",
          visible="false"
        },
        playercontroller={
          speed="175",
          maxJump="2",
          jumpStr="7200",
          camID="6"
        },
        audiolistener={
          position="0 0 0"
        },
        audiosource={
            sound="jump.wav",
            volume="0.25",
            velocity="0,0,0"
        }
      }
    },
    {
      name="Camera",
      id=6,
      components={
        transform={
          position="0,0,0",
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
          color="0,0,0"
        },
        cameracontroller={
          sensibility="1"
        }
      }
    },
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
          material="metalPlatform",
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

        },
        lifetime={
          life="20"
        },
      }
    },
    {
      name="Builder",
      id=5,
      components={
        levelbuilder={
          platformprefab="platform.prefab",
          lastplatform="4",
          time="3.5",
          turretprefab="torreta.prefab",
          dronprefab="dron.prefab",
          enemychance="50",
          turretchance="50"
        },
        audiosource={
          sound="MetalSmack.wav",
          volume="0.25",
          velocity="0,0,0"
        },
        transform={
          position="0,0,0",
          rotation="0,0,0",
          scale="1,1,1",
          parent="-1"
        }
      }
    },
    {
      name="skyBox",
      id=6,
      components={
        transform={
          position="0,0,0",
          rotation="0,0,0",
          scale="1,1,1",
          parent="-1"
        },
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
    {
      name="musicBox",
      id=7,
      components={
        transform={
          position="0,0,0",
          rotation="0,0,0",
          scale="1,1,1",
          parent="-1"
        },
        musicplayer={
        },
        audiosource={
          sound="CyberpunkMoonlightSonata.mp3",
          volume="0.125",
          velocity="0,0,0"
        }
      }
    }
  }
}

function GetMapa ()
  return mapa
end

