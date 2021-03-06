// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "libcef/browser/chrome/chrome_browser_main_extra_parts_cef.h"

#include "base/task/post_task.h"

ChromeBrowserMainExtraPartsCef::ChromeBrowserMainExtraPartsCef() = default;

ChromeBrowserMainExtraPartsCef::~ChromeBrowserMainExtraPartsCef() = default;

void ChromeBrowserMainExtraPartsCef::PostMainMessageLoopRun() {
  background_task_runner_ = base::CreateSingleThreadTaskRunner(
      {base::ThreadPool(), base::TaskPriority::BEST_EFFORT,
       base::TaskShutdownBehavior::BLOCK_SHUTDOWN, base::MayBlock()});
  user_visible_task_runner_ = base::CreateSingleThreadTaskRunner(
      {base::ThreadPool(), base::TaskPriority::USER_VISIBLE,
       base::TaskShutdownBehavior::BLOCK_SHUTDOWN, base::MayBlock()});
  user_blocking_task_runner_ = base::CreateSingleThreadTaskRunner(
      {base::ThreadPool(), base::TaskPriority::USER_BLOCKING,
       base::TaskShutdownBehavior::BLOCK_SHUTDOWN, base::MayBlock()});
}
