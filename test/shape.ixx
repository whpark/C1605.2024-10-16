module;

#include <glaze/glaze.hpp>

export module shape;
import std;

export namespace shape {

	class CShape {
	public:
		std::string m_name;

		struct glaze {
			static constexpr auto value = glz::object("name", &CShape::m_name);
		};
	};

	class CLine : public CShape {
	public:
		std::string m_line_type;

		struct glaze {
			static constexpr auto value = glz::object(
				//<<<<< C1605
				[](auto&& self) -> auto& { return (CShape&)self; },	// <<---- here.
				&CLine::m_line_type
				//>>>>> C1605
			);
		};
	};
}

