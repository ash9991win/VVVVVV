#pragma once

#include "IXmlParseHelper.h"

namespace LibraryDesktop
{
	class ActionXmlParseHelper : public IXmlParseHelper
	{
	public:
		/** @brief					Default constructor for the ActionXmlParseHelper derived class.
		*   @return                 Instance of the ActionXmlParseHelper derived class.
		*/
		explicit ActionXmlParseHelper();

		ActionXmlParseHelper(const ActionXmlParseHelper& otherSharedData) = delete;

		ActionXmlParseHelper& operator=(const ActionXmlParseHelper& otherSharedData) = delete;

		/** @brief					Default destructor for the ActionXmlParseHelper derived class.
		*
		*/
		virtual ~ActionXmlParseHelper();

		/** @brief					Initializes any member data this helper may have.
		*
		*/
		virtual void Initialize() override {}

		/** @brief					Pure virtual reporter for starting XML tags that dictates whether or not this helper is designed to handle said tag.
		*	@param userData			Shared data the parse master provides to its helpers.
		*	@param name				Name of the starting XML tag.
		*	@param attributes		List of strings representing attributes within the start tag. (This is null if there are no attributes.)
		*	@return					True if this helper handles this, and false otherwise.
		*/
		virtual bool StartElementHandler(XmlParseMaster::SharedData& sharedData, const std::string& name, HashMap<std::string, std::string>& attributes) override;

		/** @brief					Pure virtual reporter for ending XML tags that dictates whether or not this helper is designed to handle said tag.
		*	@param userData			Shared data the parse master provides to its helpers.
		*	@param name				Name of the starting XML tag.
		*	@return					True if this helper handles this, and false otherwise.
		*/
		virtual bool EndElementHandler(XmlParseMaster::SharedData& sharedData, const std::string& name) override;

		/** @brief					Produces a new instance of the ActionXmlParseHelper class.
		*   @return					Heap-allocated instance of the ActionXmlParseHelper class.
		*/
		virtual IXmlParseHelper* Clone() const override;
	private:
		/** @brief					Name of the Action element tag.
		*
		*/
		static const std::string ACTION_TAG;

		/** @brief					Counter of how many Action objects were processed from start to finish (used in automatic name generation.)
		*
		*/
		std::uint32_t mNumActionsParsed;
	};
}

