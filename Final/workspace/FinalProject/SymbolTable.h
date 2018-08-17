/*-------------------------------------------------------------------------*
 *---									---*
 *---		SymbolTable.h						---*
 *---									---*
 *---	    This file declares and defines a class that represents	---*
 *---	the symbol table of the tiny Pascal compiler.			---*
 *---									---*
 *---	----	----	----	----	----	----	----	----	---*
 *---									---*
 *---	Version 1a		2017 June 2		Joseph Phillips	---*
 *---									---*
 *-------------------------------------------------------------------------*/

class		SymbolTable
{
  //  I.  Member vars:
  //  PURPOSE:  To keep track of which the types of declared variables.
  std::map<std::string,simpleType_ty>
				varToTypeMap_;

  //  PURPOSE:  To keep track of the variable number (the stack offset) of
  //  	declared variables.
  std::map<std::string,int>	varToOffsetMap_;

  //  II.  Disallowed auto-generated methods:
  //  No copy constructor:
  SymbolTable			(const SymbolTable&
				);

  //  No copy assignment op:
  SymbolTable&	operator=	(const SymbolTable&
				);

protected :
  //  III.  Protected methods:

public :
  //  IV.  Constructor(s), assignment op(s), factory(s) and destructor:
  //  PURPOSE:  To '*this' into make an initially empty SymbolTable.
  SymbolTable			()
  				{ }

  //  PURPOSE:  To release the resources of '*this'.  No parameters.  No
  //	return value.
  ~SymbolTable			()
  				{ }

  //  V.  Accessors:

  //  VI.  Mutators:

  //  VII.  Methods that do main and misc. work of class:
  //  PURPOSE:  To declare a variable named 'newName' of type 'newType'.
  //	Throws exception as C-string if an existing variable already has
  //	name 'newName'.  No return value.
  void		declare		(const std::string&	newName,
  				 simpleType_ty		newType
				)
				{
				  if  (varToTypeMap_.find(newName) !=
				       varToTypeMap_.end()
				      )
				    throw "Attempt to redeclare variable";

				  varToTypeMap_[newName]
					= newType;
				  varToOffsetMap_[newName]
					= VariableMention::getNextOffset();

				  *outputStreamPtr
					<< COMMENT_CHAR << " Variable: "
					<< newName << "\tOffset: "
					<< varToOffsetMap_[newName]
					<< std::endl;
				}

  //  PURPOSE:  To return the type previously given to the variable with name
  //	name 'name'.  Returns 'NO_TYPE_ST' if no such variable was
  //	declared.
  simpleType_ty	getType		(const std::string&	name
				)
				const
				{
				  std::map<std::string,simpleType_ty>::
				    const_iterator
					iter	= varToTypeMap_.find(name);

				  if  (iter == varToTypeMap_.end())
				    return(NO_TYPE_ST);

				  return(iter->second);
				}

  //  PURPOSE:  To return the offset of the variable named 'name'.
  int 		getOffset	(const std::string&  name
				)
				const
				{
				  std::map<std::string,int>::const_iterator
					iter	= varToOffsetMap_.find(name);

				  if  (iter == varToOffsetMap_.end())
				    throw "Attempt to use undeclared variable";

				  return(iter->second);
				}
};