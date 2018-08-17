/*-------------------------------------------------------------------------*
 *---									---*
 *---		LabelMention.h						---*
 *---									---*
 *---	    This file declares and defines a class that represents	---*
 *---	SPVM assembly language labels used a goto addresses.		---*
 *---									---*
 *---	----	----	----	----	----	----	----	----	---*
 *---									---*
 *---	Version 1a		2017 June 2		Joseph Phillips	---*
 *---									---*
 *-------------------------------------------------------------------------*/

class		LabelMention
{
  //  I.  Member vars:
  //  PURPOSE:  To hold the next label number to use:
  static
  int		nextLabelId__;

  //  PURPOSE:  To hold the label id of '*this' LabelMention:
  int		labelId_;

  //  II.  Protected methods:
  //  PURPOSE:  No copy assignment op:
  LabelMention&	operator=	(const LabelMention&
				);

protected :
  //  III.  Protected methods:

public :
  //  IV.  Constructor(s), assignment op(s), factory(s) and destructor:
  //  PURPOSE:  To make '*this' into the next new LabelMention instance.
  //  	No parameters.  No return value.
  LabelMention			() :
				labelId_(nextLabelId__++)
				{ }

  //  PURPOSE:  To make '*this' a copy of 'rhs'.  No return value.
  LabelMention			(const LabelMention&	rhs
				) :
				labelId_(rhs.getId())
				{ }

  //  PURPOSE:  To release the resources of '*this'.  No parameters.  No return
  //	value.
  ~LabelMention			()
				{ }

  //  V.  Accessors:
  //  PURPOSE:  To return the label id of '*this'.  No parameters.
  int		getId		()
  				const
				{ return(labelId_); }

  //  VI.  Mutators:

  //  VII.  Method that do main and misc. work of class:

};


//  PURPOSE:  To output '*toPrint' to 'os'.  Returns 'os'.
extern
std::ostream&	operator<<	(std::ostream&		os,
				 const LabelMention*	toPrint
				);


//  PURPOSE:  To output 'toPrint' to 'os'.  Returns 'os'.
extern
std::ostream&	operator<<	(std::ostream&		os,
				 const LabelMention&	toPrint
				);