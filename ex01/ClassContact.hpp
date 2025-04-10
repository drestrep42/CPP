/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassContact.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:12:56 by drestrep          #+#    #+#             */
/*   Updated: 2025/04/10 18:19:55 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSCONTACT_HPP
# define CLASSCONTACT_HPP

#include <iostream>
#include <string>

#define	USAGE_ERROR "Correct use: ./phonebook"

class Contact
{
	private:
		std::string	FirstName;
		std::string	LastName;
		std::string	NickName;
		std::string	PhoneNumber;
		std::string	DarkestSecret;

	public:
		void	setFirstName(std::string s) {
			FirstName = s;
		}
		std::string	getFirstName(std::string s) {
			return (FirstName);
		}
		void	setLastName(std::string s) {
			LastName = s;
		}
		std::string	getLastName(std::string s) {
			return (LastName);
		}
		void	setNickName(std::string s) {
			NickName = s;
		}
		std::string	getNickName(std::string s) {
			return (NickName);
		}
		void	setPhoneNumber(std::string s) {
			PhoneNumber = s;
		}
		std::string	getPhoneNumber(std::string s) {
			return (PhoneNumber);
		}
		void	setDarkestSecret(std::string s) {
			DarkestSecret = s;
		}
		std::string	getDarkestSecret(std::string s) {
			return (DarkestSecret);
		}
};

#endif