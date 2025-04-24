/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassContact.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:12:56 by drestrep          #+#    #+#             */
/*   Updated: 2025/04/24 18:38:15 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSCONTACT_HPP
# define CLASSCONTACT_HPP

#include <signal.h>
#include <iostream>
#include <iomanip>
#include <string>

#define	USAGE_ERROR "Correct use: ./phonebook"
#define INVALID_COMMAND "Invalid command"

class Contact
{
	private:
		std::string	FirstName;
		std::string	LastName;
		std::string	NickName;
		std::string	PhoneNumber;
		std::string	DarkestSecret;
		int	Init = 0;

	public:
        std::string	getFirstName() { return (FirstName); }
        std::string	getLastName() { return (LastName); }
        std::string	getNickName() { return (NickName); }
        std::string	getPhoneNumber() { return (PhoneNumber); }
        std::string	getDarkestSecret() { return (DarkestSecret); }
		int			getInit() { return (Init); }
		void	    setFirstName(std::string s) { FirstName = s; }
		void	    setLastName(std::string s) { LastName = s; }
		void	    setNickName(std::string s) { NickName = s; }
		void	    setPhoneNumber(std::string s) { PhoneNumber = s; }
		void	    setDarkestSecret(std::string s) { DarkestSecret = s; }
		void		setInit(int n) { Init = n; }
};

#endif