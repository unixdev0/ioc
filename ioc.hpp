
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
                /// Generic placeholder to store typed content in to be used inside the same collection
                class UntypedPlaceholder {
                public:
                    virtual void __RTTI__() { /* Trick the compiler to generate vtable and enable RTTI placeholder */ }
                    virtual ~UntypedPlaceholder() { /* NC */ }
                };

                /// Typed placeholder to store creation and instance of typed instances
                template <typename T>
                class Placeholder : public UntypedPlaceholder {
                public:
                    std::shared_ptr<T> _instance; /* to store typed class instance */
                    virtual void __RTTI__() { /* Matches its parent's purpose */ }
                    virtual ~Placeholder() { /* NC */ }
                };

                /// Inversion Of Control Framework Main
				class Ioc {
				private:
					/// Collection that stores on-the-fly instance creation logic
					std::map<std::string, std::function<void*()>> _creators;
					/// Collection that stores the actual instances pre-created by
					/// the callee (pluggable components) of the framework and stored inside the framework
					std::map<std::string, std::shared_ptr<UntypedPlaceholder>> _instances;
				private:
                    ///Remove an instance of a typed class from the instance container
                    template <typename T>
                    void remove_from_instances() {
                        std::map<std::string, std::shared_ptr<UntypedPlaceholder>>::iterator instances_iter;
                        instances_iter = _instances.find(typeid(T).name());
                        if (instances_iter != _instances.end()) {
                            _instances.erase(instances_iter);
                        }
                    }

                    ///Remove a lambda assosiated with the given type from the creator container
                    template <typename T>
                    void remove_from_creators() {
                        std::map<std::string, std::function<void*()>>::iterator creators_iter;
                        creators_iter = _creators.find(typeid(T).name());
                        if (creators_iter != _creator.end()) {
                            _creators.erase(creators_iter);
                        }
                    }
                public:
                    virtual ~Ioc() { /* NOP */ }

                    /// Register a typed class creation lambda that
                    /// will drive instantiation logic of the typed class
                    /// Note: Variadic template Ts is the sequence of this type's typed dependencies
                    template<class Tc, typename... Ts>
                    void registerClass() {
                        /// register the creation lambda
                        auto createType = [this](void) -> Tc * {
                            return new Tc ( this->getInstance<Ts>()... );
                        };
                        ///associate this lambda with a type and store in the creator map
                        _creators[ typeid(T).name() ] = createType;
                    }

                    /// Removes the association between the type and the lambda instantiation logic
                    template <typename Tc>
                    void deregesterClass() {
                        /// Check if we have any instances of this type registered
                        if (_instances.find( typeid(Tc).name() ) != _instances.end()) {
                            remove_from_instances <Tc> ();
                        }
                        /// Then check if any instantiation logic for this type is present
                        if (_creators.find( typeid(Tc).name() ) != _creators.end()) {
                            remove_from_creators <Tc> ();
                        }
                    }

				};
			}
		}
	}
}

