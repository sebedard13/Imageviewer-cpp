#pragma once
namespace SDL_adaptater {

	struct SDL_Exception {

	};


	class SDL
	{
	public:
		explicit SDL();

		~SDL();

	};

	enum SDL_INIT {
		INIT_TIMER          =0x00000001u,
		INIT_AUDIO          =0x00000010u,
		INIT_VIDEO          =0x00000020u,  /**< SDL_INIT_VIDEO implies SDL_INIT_EVENTS */
		INIT_JOYSTICK       =0x00000200u,  /**< SDL_INIT_JOYSTICK implies SDL_INIT_EVENTS */
		INIT_HAPTIC         =0x00001000u,
		INIT_GAMECONTROLLER =0x00002000u,  /**< SDL_INIT_GAMECONTROLLER implies SDL_INIT_JOYSTICK */
		INIT_EVENTS         =0x00004000u,
		INIT_SENSOR         =0x00008000u,
		INIT_NOPARACHUTE    =0x00100000u,  /**< compatibility; this flag is ignored. */
		INIT_EVERYTHING = (\
			INIT_TIMER | INIT_AUDIO | INIT_VIDEO | INIT_EVENTS | \
			INIT_JOYSTICK | INIT_HAPTIC | INIT_GAMECONTROLLER | INIT_SENSOR \
		)
	};

	enum IMG_INIT
	{
		IMG_INIT_JPG = 0x00000001,
		IMG_INIT_PNG = 0x00000002,
		IMG_INIT_TIF = 0x00000004,
		IMG_INIT_WEBP = 0x00000008,
		IMG_INIT_everything = (IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF | IMG_INIT_WEBP)
	};
}

