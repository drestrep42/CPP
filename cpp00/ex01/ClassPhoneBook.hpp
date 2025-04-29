/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassPhoneBook.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:13:44 by drestrep          #+#    #+#             */
/*   Updated: 2025/04/24 18:38:22 by drestrep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSPHONEBOOK_HPP
# define CLASSPHONEBOOK_HPP

#include "ClassContact.hpp"

class   PhoneBook  {
    public:
        Contact contact[8];
};

void	add(PhoneBook *phonebook, int *index);
void	search(PhoneBook *phonebook, int index);

#endif