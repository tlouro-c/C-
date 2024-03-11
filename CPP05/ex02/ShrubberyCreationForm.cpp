#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( std::string target )
					: AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& other ) : AForm( other )
																			, _target( other._target ) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm& other )
{
	(void)other;
	return (*this);
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	std::ofstream	target_file;

	if (!this->getIsSigned())
		throw FormNotSigned();
	else if (executor.getGrade() >= this->getExecGrade())
		throw GradeTooLowException();
  std::string filename = _target + "_shrubbery";
	target_file.open(filename.c_str());
	target_file << 
	"                                                                    ..;===+. \n\
                                                                .:=iiiiii=+= \n\
                                                             .=i))=;::+)i=+, \n\
                                                          ,=i);)I)))I):=i=; \n\
                                                       .=i==))))ii)))I:i++ \n\
                                                     +)+))iiiiiiii))I=i+:' \n\
                                .,:;;++++++;:,.       )iii+:::;iii))+i=' \n\
                             .:;++=iiiiiiiiii=++;.    =::,,,:::=i));=+' \n\
                           ,;+==ii)))))))))))ii==+;,      ,,,:=i))+=: \n\
                         ,;+=ii))))))IIIIII))))ii===;.    ,,:=i)=i+ \n\
                        ;+=ii)))IIIIITIIIIII))))iiii=+,   ,:=));=, \n\
                      ,+=i))IIIIIITTTTTITIIIIII)))I)i=+,,:+i)=i+ \n\
                     ,+i))IIIIIITTTTTTTTTTTTI))IIII))i=::i))i=' \n\
                    ,=i))IIIIITLLTTTTTTTTTTIITTTTIII)+;+i)+i` \n\
                    =i))IIITTLTLTTTTTTTTTIITTLLTTTII+:i)ii:' \n\
                   +i))IITTTLLLTTTTTTTTTTTTLLLTTTT+:i)))=, \n\
                   =))ITTTTTTTTTTTLTTTTTTLLLLLLTi:=)IIiii; \n\
                  .i)IIITTTTTTTTLTTTITLLLLLLLT);=)I)))))i; \n\
                  :))IIITTTTTLTTTTTTLLHLLLLL);=)II)IIIIi=: \n\
                  :i)IIITTTTTTTTTLLLHLLHLL)+=)II)ITTTI)i= \n\
                  .i)IIITTTTITTLLLHHLLLL);=)II)ITTTTII)i+ \n\
                  =i)IIIIIITTLLLLLLHLL=:i)II)TTTTTTIII)i' \n\
                +i)i)))IITTLLLLLLLLT=:i)II)TTTTLTTIII)i; \n\
              +ii)i:)IITTLLTLLLLT=;+i)I)ITTTTLTTTII))i; \n\
             =;)i=:,=)ITTTTLTTI=:i))I)TTTLLLTTTTTII)i; \n\
           +i)ii::,  +)IIITI+:+i)I))TTTTLLTTTTTII))=, \n\
         :=;)i=:,,    ,i++::i))I)ITTTTTTTTTTIIII)=+' \n\
       .+ii)i=::,,   ,,::=i)))iIITTTTTTTTIIIII)=+ \n\
      ,==)ii=;:,,,,:::=ii)i)iIIIITIIITIIII))i+:' \n\
     +=:))i==;:::;=iii)+)=  `:i)))IIIII)ii+' \n\
   .+=:))iiiiiiii)))+ii; \n\
  .+=;))iiiiii)));ii+ \n\
 .+=i:)))))))=+ii+ \n\
.;==i+::::=)i=; \n\
,+==iiiiii+, \n\
`+=+++;`\n" << std::endl;
	target_file.close();
}

