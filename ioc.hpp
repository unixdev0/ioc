
#pragma once

/**
 * Generic Inversion Of Control Container
 * @author unixdev0
 * @version 0.0
 */
namespace org {
	namespace unixdev {
		namespace ioc {
			namespace framework {
				class Ioc {
				private:
					/// Generic placeholder to store typed content in to be used inside the same collection
					class UntypedPlaceholder {
					public:
						virtual void __RTTI__() { /* NOP */ }
						virtual ~GenericFolder() { /* NOP */ }
					};
				};
			}
		}
	}
}

