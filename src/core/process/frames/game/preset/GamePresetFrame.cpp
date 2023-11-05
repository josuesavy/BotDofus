#include "GamePresetFrame.h"

GamePresetFrame::GamePresetFrame(QMap<SocketIO*, BotData> *connectionsData):
    AbstractFrame(connectionsData)
{

}

bool GamePresetFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::PRESETSAVEERRORMESSAGE:
    {
        PresetSaveErrorMessage message;
        message.deserialize(&reader);

        QString presetSaveErrorReasonText = "ui.preset.error.";

        switch((PresetSaveResultEnum)message.code)
        {
        case PresetSaveResultEnum::PRESET_SAVE_ERR_UNKNOWN:
            presetSaveErrorReasonText += "unknownSave";
            break;
        case PresetSaveResultEnum::PRESET_SAVE_ERR_TOO_MANY:
            presetSaveErrorReasonText += "tooMany";
            break;
        case PresetSaveResultEnum::PRESET_SAVE_ERR_INVALID_PLAYER_STATE:
            presetSaveErrorReasonText += "invalidPlayerState";
            break;
        case PresetSaveResultEnum::PRESET_SAVE_ERR_SYSTEM_INACTIVE:
            presetSaveErrorReasonText += "inactive";
            break;
        case PresetSaveResultEnum::PRESET_SAVE_ERR_INVALID_ID:
            presetSaveErrorReasonText += "badId";
            break;
        }

        error(sender) << D2OManagerSingleton::get()->getI18N()->getText(presetSaveErrorReasonText);
    }
        break;
    }

    return messageFound;
}
