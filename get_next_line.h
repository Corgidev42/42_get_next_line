/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:32:45 by dev               #+#    #+#             */
/*   Updated: 2025/02/13 12:52:25 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/**
 * @brief Calcule la longueur d'une chaîne de caractères.
 *
 * Cette fonction prend en entrée une chaîne de caractères de type const char*
 * et retourne la longueur de cette chaîne, c'est-à-dire le nombre de caractères
 * avant le caractère nul '\0'.
 *
 * @param s La chaîne de caractères dont on veut connaître la longueur.
 * @return La longueur de la chaîne de caractères.
 */
size_t		ft_strlen(const char *s);

/**
 * @brief Trouve la première occurrence du caractère c dans la chaîne s.
 *

	* Cette fonction recherche la première
		occurrence du caractère c (converti en char)

	* dans la chaîne pointée par s.
		Le caractère nul de fin est inclus dans la recherche.
 *
 * @param s La chaîne de caractères dans laquelle chercher.
 * @param c Le caractère à trouver.

	* @return Un pointeur sur la première
		occurrence du caractère c dans la chaîne s,
 * 			ou NULL si le caractère n'est pas trouvé.
 */
char		*ft_strchr(const char *s, int c);

/**
 * @brief Duplique une chaîne de caractères.
 *
	* Cette fonction alloue suffisamment
		de mémoire pour copier la chaîne de caractères
 			passée en argument,
				puis copie cette chaîne dans la nouvelle zone de mémoire allouée.
 *
 * @param s1 La chaîne de caractères à dupliquer.
 * @return Un pointeur vers la nouvelle chaîne de caractères dupliquée,
	ou NULL si
 *         l'allocation de mémoire échoue.
 */
char		*ft_strdup(const char *s1);

/**
 * @brief Concatène deux chaînes de caractères.
 *
 * Cette fonction alloue (avec malloc) et retourne une nouvelle chaîne,
 * résultat de la concaténation de s1 et s2.
 *
 * @param s1 La première chaîne de caractères.
 * @param s2 La deuxième chaîne de caractères.
 * @return La nouvelle chaîne de caractères résultant de la concaténation
 *         de s1 et s2, ou NULL si l'allocation échoue.
 */
char		*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Extrait une sous-chaîne d'une chaîne donnée.
 *
 * Cette fonction alloue (avec malloc) et retourne une nouvelle chaîne,
	qui est une copie de la partie de la
		chaîne 's' qui commence à l'index 'start'
 			et qui a une longueur maximale de 'len' caractères.
 *
 * @param s La chaîne de caractères source.
 * @param start L'index de début de la sous-chaîne dans la chaîne source.
 * @param len La longueur maximale de la sous-chaîne à extraire.
 * @return La sous-chaîne extraite. NULL si l'allocation échoue.
 */
char		*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * @brief Copie une chaîne de caractères depuis une source vers une destination.
 *
 * Cette fonction copie jusqu'à dstsize
	- 1 caractères de la chaîne src vers dst,

	* en terminant par un caractère nul ('\0').
		Si la longueur de src est supérieure
 * ou égale à dstsize, la chaîne résultante dans dst ne sera pas terminée par un
 * caractère nul.
 *
 * @param dst Le buffer de destination où la chaîne sera copiée.
 * @param src La chaîne source à copier.
 * @param dstsize La taille du buffer de destination.
 * @return La longueur totale de la chaîne que la fonction a essayé de créer,
 *         c'est-à-dire la longueur de src.
 */
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);

/**

	* @brief Concatène deux chaînes de
		caractères en s'assurant que la taille totale
 *			de la chaîne résultante ne dépasse pas dstsize.
 *
 * @param dst La chaîne de destination où src sera concaténée.
 * @param src La chaîne source à concaténer à dst.
 * @param dstsize La taille totale allouée pour la chaîne de destination,
	y compris
 *                l'espace pour le caractère nul de fin.
 * @return La longueur totale de la chaîne qu'elle a essayé de créer,
	c'est-à-dire
 *         la longueur initiale de dst plus la longueur de src.
 */
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);

/**
 * @brief Extrait une ligne de la chaîne sauvegardée.
 *
 * Cette fonction extrait une ligne de la chaîne sauvegardée `saved`. Si une
 * nouvelle ligne ('\n') est trouvée, elle extrait la ligne jusqu'à et y compris
 * le caractère de nouvelle ligne. Sinon, elle extrait toute la chaîne.
 *
 * @param saved Un pointeur vers la chaîne sauvegardée. La chaîne sauvegardée
 * sera mise à jour pour supprimer la ligne extraite.
 *
 * @return La ligne extraite. Si la chaîne sauvegardée est vide ou NULL, la
 * fonction retourne NULL.
 */
static char	*get_line(char **saved);

/**
 * @brief Lit une ligne depuis un descripteur de fichier.
 *
 * Cette fonction lit une ligne complète depuis le descripteur de fichier donné.
	* Elle utilise un tampon statique pour
		stocker les données lues entre les appels.
 *
 * @param fd Le descripteur de fichier à lire.
 * @return Un pointeur vers la ligne lue,
	ou NULL en cas d'erreur ou de fin de fichier.
 *

	* La fonction alloue dynamiquement de la mémoire
		pour la ligne retournée. Il est de la
 			responsabilité de l'appelant de
				libérer cette mémoire après utilisation.
 *

	* La fonction utilise un tampon de taille
		BUFFER_SIZE pour lire les données du fichier.
			Si BUFFER_SIZE est inférieur ou égal à 0,
				ou si une erreur de lecture se produit,
					la fonction retourne NULL.
 *
 * La fonction utilise les fonctions auxiliaires suivantes :
 * - read_error() : Gère les erreurs de lecture et libère les ressources.
 * - ft_strchr() : Cherche un caractère dans une chaîne.
 * - ft_strdup() : Duplique une chaîne.
 * - ft_strjoin() : Concatène deux chaînes.
 * - get_line() : Extrait une ligne complète de la chaîne sauvegardée.
 */
char		*get_next_line(int fd);

/**
 * @brief Gère les erreurs de lecture et libère les ressources allouées.
 *
 * Cette fonction est appelée lorsqu'une erreur de lecture se produit ou
 * lorsque la fin du fichier est atteinte. Elle libère le tampon de lecture
 * et la chaîne sauvegardée, puis retourne une copie de la chaîne sauvegardée
 * si des données ont été lues avec succès.
 *

	* @param saved Un pointeur vers la chaîne
		sauvegardée contenant les données lues précédemment.

	* @param bytes_read Le nombre d'octets
		lus lors de la dernière opération de lecture.
 * @param buffer Le tampon de lecture à libérer.

	* @return Une copie de la chaîne sauvegardée 
		si des données ont été lues avec succès,
 *         NULL sinon.
 */
char		*read_error(char **saved, ssize_t bytes_read, char *buffer);

#endif
