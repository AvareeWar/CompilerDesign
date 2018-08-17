/*-------------------------------------------------------------------------*
 *---									---*
 *---		VariableMention.h					---*
 *---									---*
 *---	    This file declares and defines a class that represents	---*
 *---	SPVM assembly language variables.				---*
 *---									---*
 *---	----	----	----	----	----	----	----	----	---*
 *---									---*
 *---	Version 1a		2017 June 2		Joseph Phillips	---*
 *---									---*
 *-------------------------------------------------------------------------*/

class		VariableMention
{
  //  I.  Member vars:
  //  PURPOSE:  To hold the next auto-generated variable number to use:
  static
  int				nextAutoVarId__;

  //  PURPOSE:  To name of the variable that '*this' mentions.
  std::string			name_;

  //  PURPOSE:  To hold the stack offset of a mentioned variable.
  int				offset_;

  //  II.  Protected methods:
  //  PURPOSE:  No copy assignment op:
  VariableMention&	operator=
				(const VariableMention&
				);

protected :
  //  III.  Protected methods:

public :
  //  IV.  Constructor(s), assignment op(s), factory(s) and destructor:
  //  PURPOSE:  To make '*this' into the next new VariableMention instance.
  //  	No parameters.  No return value.
  VariableMention		() :
				name_()
				{
				  std::stringstream	strm;

				  strm << AUTO_VAR_NAME_PREFIX
				       << nextAutoVarId__++;
				  name_	  = strm.str();
				}

  //  PURPOSE:  To make '*this' mention the variable named 'cPtr'.
  //  	No parameters.  No return value.
  VariableMention		(const char*	cPtr
  				);

  //  PURPOSE:  To make '*this' mention the variable named 'newName'.
  //  	No parameters.  No return value.
  VariableMention		(const std::string&	newName
  				);

  //  PURPOSE:  To make '*this' a copy of 'rhs'.  No return value.
  VariableMention		(const VariableMention&	rhs
				) :
				name_(rhs.getName())
				{ }

  //  PURPOSE:  To release the resources of '*this'.  No parameters.  No return
  //	value.
  ~VariableMention		()
				{ }

  //  V.  Accessors:
  //  PURPOSE:  To return the name of '*this'.  No parameters.
  const	std::string&
		getName		()
  				const
				{ return(name_); }

  //  VI.  Mutators:

  //  VII.  Method that do main and misc. work of class:
  //  PURPOSE:  To return the next available stack offset.  No parameters.
  static
  int		getNextOffset	()
  				{ return(nextAutoVarId__++); }

};


//  PURPOSE:  To output '*toPrint' to 'os'.  Returns 'os'.
extern
std::ostream&	operator<<	(std::ostream&		os,
				 const VariableMention*	toPrint
				);


//  PURPOSE:  To output 'toPrint' to 'os'.  Returns 'os'.
extern
std::ostream&	operator<<	(std::ostream&		os,
				 const VariableMention&	toPrint
				);
