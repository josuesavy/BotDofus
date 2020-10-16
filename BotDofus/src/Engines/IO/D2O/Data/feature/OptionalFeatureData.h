#ifndef OPTIONALFEATUREDATA_H
#define OPTIONALFEATUREDATA_H

#include "src/Engines/IO/D2O/AbstractGameData.h"

class OptionalFeatureData : public AbstractGameData
{
public:
  int getId() const;
  QString getKeyword() const;
  bool getIsClient() const;
  bool getIsServer() const;
  bool getIsActivationOnLaunch() const;
  bool getIsActivationOnServerConnection() const;
  QString getActivationCriterions() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  QString m_keyword;
  bool m_isClient;
  bool m_isServer;
  bool m_isActivationOnLaunch;
  bool m_isActivationOnServerConnection;
  QString m_activationCriterions;
};

#endif // OPTIONALFEATUREDATA_H