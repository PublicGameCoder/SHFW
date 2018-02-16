#ifndef TEXT_H
#define TEXT_H

#include "Entity.h"

/// @brief The Text class is a collection of drawable Characters.
class Text: public Entity
{
public:
	/// @brief Constructor of the Text
	Text();
	 /// @brief Destructor of the Text
	virtual ~Text();

	/// @brief empty update function
	virtual void update() { };

	/// @brief clears all Sprites for characters
	/// @return void
	void clearMessage();
	/// @brief message getter
	/// @return std::string _message
	std::string message() { return _message; };
	/// @brief message setter also creates Characters
	/// @param m the message to be created
	/// @return void
	void message( std::string m );
	/// @brief message setter also creates Characters
	/// @param m the message to be created
	/// @param c the color of the message to be created
	/// @return void
	void message( std::string m, RGBAColor c );

private:
	std::string _message; ///< @brief the message string
};

#endif /* TEXT_H */
