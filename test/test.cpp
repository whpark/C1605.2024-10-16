#include <glaze/glaze.hpp>

import std;
import shape;

namespace NotAModule {
	class CShape {
	public:
		std::string m_name;

		struct glaze {
			static constexpr auto value = glz::object(&CShape::m_name);
		};
	};

	class CLine : public CShape {
	public:
		std::string m_line_type;

		struct glaze {
			static constexpr auto value = glz::object(
				//<<<<< OK.
				[](auto&& self) -> auto& { return (CShape&)self; },
				&CLine::m_line_type
				//>>>>> 
			);
		};
	};
}

int main() {
}

