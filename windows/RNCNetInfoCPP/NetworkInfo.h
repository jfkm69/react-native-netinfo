// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#pragma once
#include "NativeModules.h"

namespace winrt::ReactNativeNetInfo::implementation {

	class NetworkInfo {
	public:
		NetworkInfo();
        bool IsConnected();
		std::string ConnectivityType();
        std::string CellularGeneration();
        bool IsConnectionExpensive();
        std::string GetSsid();
        uint8_t GetStrength();
        winrt::Windows::Foundation::IAsyncOperation<int64_t> GetFrequency() noexcept;
        void StatusChanged(const winrt::Windows::Networking::Connectivity::NetworkStatusChangedEventHandler& handler);

        static constexpr auto CONNECTION_TYPE_CELLULAR = "cellular";
        static constexpr auto CONNECTION_TYPE_ETHERNET = "ethernet";
        static constexpr auto CONNECTION_TYPE_NONE = "none";
        static constexpr auto CONNECTION_TYPE_UNKNOWN = "unknown";
        static constexpr auto CONNECTION_TYPE_WIFI = "wifi";
        static constexpr auto CONNECTION_TYPE_OTHER = "other";

        static constexpr auto CELLULAR_GENERATION_2G = "2g";
        static constexpr auto CELLULAR_GENERATION_3G = "3g";
        static constexpr auto CELLULAR_GENERATION_4G = "4g";
        static constexpr auto CELLULAR_GENERATION_NONE = nullptr;
        static constexpr auto CELLULAR_GENERATION_UNKNOWN = nullptr;

	private:
		winrt::Windows::Networking::Connectivity::NetworkInformation::NetworkStatusChanged_revoker m_networkStatusChangedRevoker{};
        winrt::Windows::Networking::Connectivity::NetworkStatusChangedEventHandler m_statusChangedHandler{};
        winrt::Windows::Networking::Connectivity::ConnectionProfile m_profile{ nullptr };
        winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::WiFi::WiFiAdapter> getConnectedWiFiAdapter(winrt::hstring inetSsid);
        winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::WiFi::WiFiAvailableNetwork> getConnectedNetwork(winrt::hstring inetSsid);
	};

}