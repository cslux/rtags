/* This file is part of RTags.

   RTags is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   RTags is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with RTags.  If not, see <http://www.gnu.org/licenses/>. */

#ifndef JOBANNOUNCEMENTMESSAGE_H
#define JOBANNOUNCEMENTMESSAGE_H

#include "RTagsMessage.h"

class JobAnnouncementMessage : public RTagsMessage
{
public:
    enum { MessageId = JobAnnouncementId };

    JobAnnouncementMessage(const String &host = String(), uint16_t port = 0)
        : RTagsMessage(MessageId), mHost(host), mPort(port)
    {
    }

    String host() const { return mHost; }
    uint16_t port() const { return mPort; }

    virtual void encode(Serializer &serializer) const
    {
        serializer << mHost << mPort;
    }
    virtual void decode(Deserializer &deserializer)
    {
        deserializer >> mHost >> mPort;
    }
private:
    String mHost;
    uint16_t mPort;
};

#endif
