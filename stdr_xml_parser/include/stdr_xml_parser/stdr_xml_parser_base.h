/******************************************************************************
   STDR Simulator - Simple Two DImensional Robot Simulator
   Copyright (C) 2013 STDR Simulator
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation,
   Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
   
   Authors : 
   * Manos Tsardoulias, etsardou@gmail.com
   * Aris Thallas, aris.thallas@gmail.com
   * Chris Zalidis, zalidis@gmail.com 
******************************************************************************/

#ifndef STDR_XML_PARSER__BASE
#define STDR_XML_PARSER__BASE

#include "stdr_xml_parser/stdr_xml_parser_msg_creator.h"

/**
@namespace stdr_xml_parser
@brief The main namespace for STDR GUI XML parser
**/ 
namespace stdr_xml_parser
{
  /**
  @class Base
  @brief Implements the main functionalities of the high-level parser
  **/ 
  class Base
  {
    private:
      
      //!< Base node of the parsed file
      Node* base_node_;
      //!< The path for stdr_resources
      std::string base_path_;
      //!< List of non-mergable tags. Read from stdr_multiple_allowed.xml
      std::set<std::string> non_mergable_tags_;
      
      //!< Object of Message creator
      MessageCreator creator_;
      
      /**
      @brief Low-level recursive function for parsing the xml specifications file
      @param node [TiXmlNode*] The xml node to start from
      @return void
      **/
      void parseSpecifications(TiXmlNode* node);
      
      /**
      @brief Low-level recursive function for parsing the xml robot file
      @param node [TiXmlNode*] The xml node to start from
      @param n [Node*] The stdr xml tree node to update
      @return void
      **/
      void parseLow(TiXmlNode* node,Node* n);
      
      /**
      @brief Private function that initiates the parsing of an xml file
      @param file_name [std::string] The xml file name
      @param n [Node*] The stdr xml tree node to update
      @return void
      **/
      void parse(std::string file_name,Node* n);
      
      /**
      @brief Debug recursive function - Prints the xml tree
      @param n [Node*] The stdr xml tree node to begin
      @param indent [std::string] The indentation for the specific node
      @return void
      **/
      void printParsedXml(Node* n,std::string indent);
      
      /**
      @brief Recursive function - Expands the 'filename' nodes and eliminates them
      @param n [Node*] The stdr xml tree node to begin
      @return bool : True is a 'filename' node was expanded
      **/
      bool eliminateFilenames(Node* n);
      
      /**
      @brief High level function that eliminates the 'filename' nodes. Calls the eliminateFilenames(Node* n) function until it returns false
      @return void
      **/
      void eliminateFilenames(void);
      
      /**
      @brief Recursive function - Merges the nodes that do not exist in non_mergable_tags_
      @param n [Node*] The stdr xml tree node to begin
      @return bool : True is a ndoe was merged
      **/
      bool mergeNodes(Node* n);
      
      /**
      @brief High level function that merges similar nodes. Calls the mergeNodes(Node* n) function until it returns false
      @return void
      **/
      void mergeNodes(void);
      
      /**
      @brief Merges the leaves of the xml tree, which are the value nodes
      @param n [Node*] The stdr xml tree node to begin
      @return void
      **/
      void mergeNodesValues(Node* n);
      
      /**
      @brief Performs a allowed - validity check on the xml tree
      @param n [Node*] The stdr xml tree node to begin
      @return bool : True is the xml is allowed-valid
      **/
      bool validityAllowedCheck(Node* n);
      
      /**
      @brief Performs a required - validity check on the xml tree
      @param n [Node*] The stdr xml tree node to begin
      @return bool : True is the xml is required-valid
      **/
      bool validityRequiredCheck(Node* n);
      
      /**
      @brief Parses the mergabl speciications file
      @return void
      **/
      void parseMergableSpecifications(void);
      
      /**
      @brief Loads the specifications file and parses it
      @return void
      **/
      void initialize(void);
      
      /**
      @brief Parses an xml file
      @param file_name [std::string] The xml filename
      @return void
      **/
      void parse(std::string file_name);
      
      /**
      @brief Prints the specifications
      @return void
      **/
      void printSpecifications(void);
      
      /**
      @brief Prints the parsed xml
      @return void
      **/
      void printParsedXml(void);
      
    public:
    
      /**
      @brief Default constructor
      @return void
      **/
      Base(void);
      
      /**
      @brief Parses an xml file and produces a stdr_msgs::RobotMsg message
      @param file_name [std::string] The xml filename
      @return stdr_msgs::RobotMsg : The robot message
      **/
      stdr_msgs::RobotMsg createRobotMessage(std::string file_name);
  };
}
#endif
