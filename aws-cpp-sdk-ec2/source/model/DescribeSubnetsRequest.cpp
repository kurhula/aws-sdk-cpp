﻿/*
* Copyright 2010-2017 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/

#include <aws/ec2/model/DescribeSubnetsRequest.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>

using namespace Aws::EC2::Model;
using namespace Aws::Utils;

DescribeSubnetsRequest::DescribeSubnetsRequest() : 
    m_filtersHasBeenSet(false),
    m_subnetIdsHasBeenSet(false),
    m_dryRun(false),
    m_dryRunHasBeenSet(false),
    m_nextTokenHasBeenSet(false),
    m_maxResults(0),
    m_maxResultsHasBeenSet(false)
{
}

Aws::String DescribeSubnetsRequest::SerializePayload() const
{
  Aws::StringStream ss;
  ss << "Action=DescribeSubnets&";
  if(m_filtersHasBeenSet)
  {
    unsigned filtersCount = 1;
    for(auto& item : m_filters)
    {
      item.OutputToStream(ss, "Filter.", filtersCount, "");
      filtersCount++;
    }
  }

  if(m_subnetIdsHasBeenSet)
  {
    unsigned subnetIdsCount = 1;
    for(auto& item : m_subnetIds)
    {
      ss << "SubnetId." << subnetIdsCount << "="
          << StringUtils::URLEncode(item.c_str()) << "&";
      subnetIdsCount++;
    }
  }

  if(m_dryRunHasBeenSet)
  {
    ss << "DryRun=" << std::boolalpha << m_dryRun << "&";
  }

  if(m_nextTokenHasBeenSet)
  {
    ss << "NextToken=" << StringUtils::URLEncode(m_nextToken.c_str()) << "&";
  }

  if(m_maxResultsHasBeenSet)
  {
    ss << "MaxResults=" << m_maxResults << "&";
  }

  ss << "Version=2016-11-15";
  return ss.str();
}


void  DescribeSubnetsRequest::DumpBodyToUrl(Aws::Http::URI& uri ) const
{
  uri.SetQueryString(SerializePayload());
}
